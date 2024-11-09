Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
  
Example 2:
Input: s = "cbbd"
Output: "bb"

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
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLen = 0;
        int startPoint = 0;

        memset(dp, -1, sizeof(dp));

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(solve(i, j, s) == true) {
                    if(j-i+1 > maxLen) {
                        maxLen = j-i+1;
                        startPoint = i;
                    }
                }
            }
        }
        return s.substr(startPoint, maxLen);
    }
};
