// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
// Evaluate the expression. Return an integer that represents the value of the expression.
// Note that:
// The valid operators are '+', '-', '*', and '/'.
// Each operand may be an integer or another expression.
// The division between two integers always truncates toward zero.
// There will not be any division by zero.
// The input represents a valid arithmetic expression in a reverse polish notation.
// The answer and all the intermediate calculations can be represented in a 32-bit integer.

// Example 1:
// Input: tokens = ["2","1","+","3","*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9
  
// Example 2:
// Input: tokens = ["4","13","5","/","+"]
// Output: 6
// Explanation: (4 + (13 / 5)) = 6
  
// Example 3:
// Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
// Output: 22
// Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
// = ((10 * (6 / (12 * -11))) + 17) + 5
// = ((10 * (6 / -132)) + 17) + 5
// = ((10 * 0) + 17) + 5
// = (0 + 17) + 5
// = 17 + 5
// = 22

//Approach : Using Stack
//T.C : O(n)
//S.C : O(n)

class Solution {
public:
    int operate(int a, int b, string& token) {
        if(token == "+") {
            return a + b;
        }

        if(token == "-") {
            return a - b;
        }

        if(token == "*") {
            return (long)a * (long)b;
        }

        if(token == "/") {
            return a / b;
        }
        return -1;
    }
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> s;

        for(string& token : tokens) {
            if(token == "+" || token == "-" || token == "*" || token == "/") {
                int b = s.top();
                s.pop();

                int a = s.top();
                s.pop();

                int result = operate(a, b, token);
                s.push(result);
            }
            else { 
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};
