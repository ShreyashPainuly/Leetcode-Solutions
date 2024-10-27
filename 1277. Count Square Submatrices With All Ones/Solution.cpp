// Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

// Example 1:
// Input: matrix =
// [
//   [0,1,1,1],
//   [1,1,1,1],
//   [0,1,1,1]
// ]
// Output: 15
// Explanation: 
// There are 10 squares of side 1.
// There are 4 squares of side 2.
// There is  1 square of side 3.
// Total number of squares = 10 + 4 + 1 = 15.
  
// Example 2:
// Input: matrix = 
// [
//   [1,0,1],
//   [1,1,0],
//   [1,1,0]
// ]
// Output: 7
// Explanation: 
// There are 6 squares of side 1.  
// There is 1 square of side 2. 
// Total number of squares = 6 + 1 = 7.

//Approach - 1 (simple Recursion Memoization) - Same as Maximal Square
//T.C : O(m*n)
//S.C : O(m*n)

class Solution {
public:
    int m, n;
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& t) {

        if (i >= grid.size() || j >= grid[0].size())
            return 0;

        if (grid[i][j] == 0)
            return 0;

        if (t[i][j] != -1)
            return t[i][j];

        // Right
        int right = solve(i, j + 1, grid, t);
        // Diagonal
        int diagonal = solve(i + 1, j + 1, grid, t);
        // Below
        int below = solve(i + 1, j, grid, t);

        return t[i][j] = 1 + min({right, diagonal, below});
    }
    int countSquares(vector<vector<int>>& grid) {
        int result = 0;
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> t(m, vector<int>(n, -1));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                result += solve(i, j, grid, t);
            }
        }
        return result;
    }
};

//Approach - 2 (simple Bottom Up - Same as Maximal Square 
//T.C : O(m*n)
//S.C : O(m*n)

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> t(m, vector<int>(n, 0));
        int result = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 || j == 0) {
                    t[i][j] = matrix[i][j];
                } else {
                    if(matrix[i][j] == 1) {
                        // Because, if you have any 0, then you cannot expand side of square
                        t[i][j] = 1 + min({t[i-1][j], t[i][j-1], t[i-1][j-1]});
                    }
                }
                result += t[i][j];
            }
        }
        
        return result;
    }
};
