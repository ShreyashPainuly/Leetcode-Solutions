// Example 1:
// Input: expression = "2-1-1"
// Output: [0,2]

// Explanation:
// ((2-1)-1) = 0 
// (2-(1-1)) = 2

// Example 2:
// Input: expression = "2*3-4*5"
// Output: [-34,-14,-10,-10,10]

// Explanation:
// (2*(3-(4*5))) = -34 
// ((2*3)-(4*5)) = -14 
// ((2*(3-4))*5) = -10 
// (2*((3-4)*5)) = -10 
// (((2*3)-4)*5) = 10

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
         vector<int> result;

        // Loop through each character in the expression
        for (int i = 0; i < expression.size(); i++) {
            char ch = expression[i];

            // If the character is an operator, we split the expression around it
            if (ch == '+' || ch == '-' || ch == '*') {
                // Solve the left part of the expression (before the operator)
                vector<int> left = diffWaysToCompute(expression.substr(0, i));

                // Solve the right part of the expression (after the operator)
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));

                // Combine the results from the left and right parts using the operator
                for (int l : left) {
                    for (int r : right) {
                        if (ch == '+') {
                            result.push_back(l + r);
                        } 
                        else if (ch == '-') {
                            result.push_back(l - r);
                        } 
                        else if (ch == '*') {
                            result.push_back(l * r);
                        }
                    }
                }
            }
        }

        // If no operator is found, it means the expression is a single number
        if (result.empty()) {
            result.push_back(stoi(expression)); 
        }
        return result;
    }
};
