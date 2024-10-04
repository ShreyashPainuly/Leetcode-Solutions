// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
// You have the following three operations permitted on a word:
// Insert a character
// Delete a character
// Replace a character
 
// Example 1:
// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation: 
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')
  
// Example 2:
// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation: 
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')

class Solution {
public:
    int editDistance(string& s1, string& s2, int m, int n, int t[501][501]) {
        if(m == 0) {
            return n;
        }

        if(n == 0) {
            return m;
        }
        
        if(t[m][n] != -1) {
            return t[m][n];
        }
        if(s1[m-1] == s2[n-1]) {
            return t[m][n] = editDistance(s1, s2, m-1, n-1, t);
        }

        else {
            return t[m][n] = 1 + min({editDistance(s1, s2, m, n-1, t), editDistance(s1, s2, m-1, n, t), editDistance(s1, s2, m-1, n-1, t)});
        }
    }

    int minDistance(string s1, string s2) {
        int t[501][501];
        memset(t, -1, sizeof(t));
        return editDistance(s1, s2, s1.length(), s2.length(), t);
    }
};
