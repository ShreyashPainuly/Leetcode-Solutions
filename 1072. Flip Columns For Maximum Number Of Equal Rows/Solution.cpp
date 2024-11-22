// You are given an m x n binary matrix matrix.
// You can choose any number of columns in the matrix and flip every cell in that column (i.e., Change the value of the cell from 0 to 1 or vice versa).
// Return the maximum number of rows that have all values equal after some number of flips.

// Example 1:
// Input: matrix = [[0,1],[1,1]]
// Output: 1
// Explanation: After flipping no values, 1 row has all values equal.

// Example 2:
// Input: matrix = [[0,1],[1,0]]
// Output: 2
// Explanation: After flipping values in the first column, both rows have equal values.

// Example 3:
// Input: matrix = [[0,0,0],[0,0,1],[1,1,0]]
// Output: 2
// Explanation: After flipping values in the first two columns, the last two rows have equal values.

//Approach-1 : Brute Force
//T.C : O(row^2 * col)
//S.C : O(col)

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        int maxRows = 0;

        for (auto& currRow : matrix) {

            vector<int> inverted(n);
            int count = 0;

            
            for (int col = 0; col < n; col++) {
                inverted[col] = currRow[col] == 0 ? 1 : 0;
            }

            for (auto& row : matrix) {

                if (row == currRow || row == inverted) {
                    count++;
                }
            }

            maxRows = max(maxRows, count);
        }

        return maxRows;
    }
};


//Approach-2 : Using hashmap to store patterns
//T.C : O(row * col)
//S.C : O(row*col)

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_map<string, int> mp;

        for(auto &row : matrix) {
            string rowKaNature = "";

            int firstVal = row[0];
            for(int col = 0; col < n; col++) { 
                rowKaNature += (row[col] == firstVal) ? "S" : "B";
            }

            mp[rowKaNature]++;
        }

        int maxRows = 0;
        for(auto &it : mp) {
            maxRows = max(maxRows, it.second);
        }

        return maxRows;
    }
};
