// You are given an n x n integer matrix. You can do the following operation any number of times:
// Choose any two adjacent elements of matrix and multiply each of them by -1.
// Two elements are considered adjacent if and only if they share a border.
// Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.

// Example 1:
// Input: matrix = [[1,-1],[-1,1]]
// Output: 4
// Explanation: We can follow the following steps to reach sum equals 4:
// - Multiply the 2 elements in the first row by -1.
// - Multiply the 2 elements in the first column by -1.
  
// Example 2:
// Input: matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]
// Output: 16
// Explanation: We can follow the following step to reach sum equals 16:
// - Multiply the 2 last elements in the second row by -1.

//Approach - Check Odd or Even count of -ves
//T.C : O(row*col)
//S.C : O(1)
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        long long sum = 0;
        int countNegatives = 0; 
        int smallestAbsoluteValue = INT_MAX;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                sum += abs(matrix[i][j]);

                countNegatives += matrix[i][j] < 0 ? 1 : 0;

                smallestAbsoluteValue = min(smallestAbsoluteValue, abs(matrix[i][j]));

            }
        }

        if(countNegatives%2 == 0) {
            return sum;
        }

        return sum - 2*smallestAbsoluteValue;
    }
};
