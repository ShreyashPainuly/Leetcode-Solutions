// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
// Note:
// A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// Only the filled cells need to be validated according to the mentioned rules.
 
// Example 1:
// Input: board = 
// [["5","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: true
  
// Example 2:
// Input: board = 
// [["8","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: false
// Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

//Approach-1 (Naive and simplest using 3 iterations of the sudoku)
class Solution {
public:
    // Traversal Function
    bool isValidBox(vector<vector<char>>& board, int sr, int er, int sc, int ec) {
        unordered_set<char> st;
        for (int i = sr; i <= er; i++) {
            for (int j = sc; j <= ec; j++) {
                if(board[i][j] == '.') {
                    continue;
                }
                if (st.find(board[i][j]) != st.end()) {
                    return false;
                } else {
                    st.insert(board[i][j]);
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        // Rows Validation
        for (int rows = 0; rows < 9; rows++) {
            // Define Set
            unordered_set<char> st;
            for (int cols = 0; cols < 9; cols++) {
                // Empty case
                if (board[rows][cols] == '.') {
                    continue;
                }
                // Repetiton Case
                if (st.find(board[rows][cols]) != st.end()) {
                    return false;
                } else {
                    st.insert(board[rows][cols]);
                }
            }
        }

        // Column Validation
        for (int cols = 0; cols < 9; cols++) {
            // Define Set
            unordered_set<char> st;
            for (int rows = 0; rows < 9; rows++) {
                // Empty case
                if (board[rows][cols] == '.') {
                    continue;
                }
                // Repetiton Case
                if (st.find(board[rows][cols]) != st.end()) {
                    return false;
                } else {
                    st.insert(board[rows][cols]);
                }
            }
        }

        // 3*3 Sub-Boxes Validation
        for (int sr = 0; sr < 9; sr += 3) {
            int er = sr + 2;
            for (int sc = 0; sc < 9; sc += 3) {
                int ec = sc + 2;
                if(!isValidBox(board, sr, er, sc, ec)) {
                    return false;
                }
            }
        }
        return true;
    }
};

//Approach-2 (One iteration using hashmap and indexing boxes)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> st;
        
        for(int i = 0; i<9; i++) {
            for(int j = 0; j<9; j++) {
                if(board[i][j] == '.') continue;
                
                string row = string(1, board[i][j]) + "_row_" + to_string(i);
                string col = string(1, board[i][j]) + "_col_" + to_string(j);
                string box = string(1, board[i][j]) + "_box_" + to_string(i/3) + "_" + to_string(j/3);
                if(st.count(row) || st.count(col) || st.count(box)) return false;
                st.insert(row);
                st.insert(col);
                st.insert(box);
            }
        }
        return true;
    }
};
