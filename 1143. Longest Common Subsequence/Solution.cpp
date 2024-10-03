// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

// Example 1:
// Input: text1 = "abcde", text2 = "ace" 
// Output: 3  
// Explanation: The longest common subsequence is "ace" and its length is 3.

// Example 2:
// Input: text1 = "abc", text2 = "abc"
// Output: 3
// Explanation: The longest common subsequence is "abc" and its length is 3.

// Example 3:
// Input: text1 = "abc", text2 = "def"
// Output: 0
// Explanation: There is no such common subsequence, so the result is 0.

class Solution {
    int m, n;
    int t[1001][1001];
private:
    int solve(string& s1, string& s2, int i, int j) {
        if(i >= m || j >= n) {
            return 0;
        }

        if(t[i][j] != -1) {
            return t[i][j];
        }

        if(s1[i] == s2[j]) {
            return t[i][j] = 1 + solve(s1, s2, i+1, j+1);
        }
        else {
            return t[i][j] =  max(solve(s1, s2, i+1, j), solve(s1, s2, i, j+1));
        }
    }
public:
    int longestCommonSubsequence(string s1, string s2) {
        m = s1.length();
        n = s2.length();
        memset(t, -1, sizeof(t));
        return solve(s1, s2, 0, 0);
    }
};
