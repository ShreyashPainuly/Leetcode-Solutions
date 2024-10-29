// You are given a 0-indexed m x n matrix grid consisting of positive integers.
// You can start at any cell in the first column of the matrix, and traverse the grid in the following way:
// From a cell (row, col), you can move to any of the cells: (row - 1, col + 1), (row, col + 1) and (row + 1, col + 1) such that the value of the cell you move to, should be strictly bigger than the value of the current cell.
// Return the maximum number of moves that you can perform.

// Example 1:
// Input: grid = [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]
// Output: 3
// Explanation: We can start at the cell (0, 0) and make the following moves:
// - (0, 0) -> (0, 1).
// - (0, 1) -> (1, 2).
// - (1, 2) -> (2, 3).
// It can be shown that it is the maximum number of moves that can be made.
  
// Example 2:
// Input: grid = [[3,2,4],[2,1,9],[1,1,7]]
// Output: 0
// Explanation: Starting from any cell in the first column we cannot perform any moves.

//Approach- Dynamic Programming
//T.C- O(n*m)
//S.C- O(n*m)

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> maxMovsAt(rows, vector<int>(cols, 0));

        for (int r = 0; r < rows; r++) {
            maxMovsAt[r][0] = 1;
        }

        int maxMovs = 0;
        for (int c = 1; c < cols; c++) {
            for (int r = 0; r < rows; r++) {
                int left =
                    (grid[r][c - 1] < grid[r][c] && maxMovsAt[r][c - 1] > 0)
                        ? maxMovsAt[r][c - 1] + 1
                        : 0;
                int leftUpD = (r - 1 >= 0 && grid[r - 1][c - 1] < grid[r][c] &&
                               maxMovsAt[r - 1][c - 1] > 0)
                                  ? maxMovsAt[r - 1][c - 1] + 1
                                  : 0;
                int leftDownD =
                    (r + 1 < rows && grid[r + 1][c - 1] < grid[r][c] &&
                     maxMovsAt[r + 1][c - 1] > 0)
                        ? maxMovsAt[r + 1][c - 1] + 1
                        : 0;

                maxMovsAt[r][c] = max(left, max(leftUpD, leftDownD));
                maxMovs = max(maxMovs, maxMovsAt[r][c] - 1);
            }
        }

        return maxMovs;
    }
};
