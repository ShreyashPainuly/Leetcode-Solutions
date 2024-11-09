// Given a string s, return the number of palindromic substrings in it.
// A string is a palindrome when it reads the same backward as forward.
// A substring is a contiguous sequence of characters within the string.

// Example 1:
// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
  
// Example 2:
// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

//Approach : Using Recursion And Memoization
//T.C : O(n^2)
//S.C : O(n^2)

class Solution {
public:
    int dp[1001][1001];
    bool solve(int i, int j, string& s) {
        if(i >= j) {
            return true;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(s[i] == s[j]) {
            return dp[i][j] = solve(i+1, j-1, s);
        }    
        else {
            return dp[i][j] = false;
        }
        i++;
        j--;
    }

    int countSubstrings(string s) {
        int n = s.length();
        int maxLen = 0;

        memset(dp, -1, sizeof(dp));

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(solve(i, j, s) == true) {
                    maxLen++;
                }
            }
        }
        return maxLen;
    }
};
