// You have intercepted a secret message encoded as a string of numbers. The message is decoded via the following mapping:
// "1" -> 'A'
// "2" -> 'B'
// ...
// "25" -> 'Y'
// "26" -> 'Z'
// However, while decoding the message, you realize that there are many different ways you can decode the message because some codes are contained in other codes ("2" and "5" vs "25").
  
// For example, "11106" can be decoded into:
// "AAJF" with the grouping (1, 1, 10, 6)
// "KJF" with the grouping (11, 10, 6)
// The grouping (1, 11, 06) is invalid because "06" is not a valid code (only "6" is valid).
// Note: there may be strings that are impossible to decode.
// Given a string s containing only digits, return the number of ways to decode it. If the entire string cannot be decoded in any valid way, return 0.
// The test cases are generated so that the answer fits in a 32-bit integer.

//Approach : Using Recursion And Memoization
//T.C : O(n)
//S.C : O(1)

class Solution {
public:
    int dp[101];
    int solve(int i, string& s, int n) {
        if(dp[i] != -1) {
            return dp[i];
        }

        if (i == n) {
            return dp[i] = 1;
        }

        if (s[i] == '0') {
            return dp[i] = 0;
        }

        int include_only_ith_character = solve(i + 1, s, n);

        int include_ithplus1_character = 0;
        if (i + 1 < n) {
            if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')) {
                include_ithplus1_character = solve(i + 2, s, n);
            }
        }

        return dp[i] = include_only_ith_character + include_ithplus1_character;
    }

    int numDecodings(string s) {
        int n = s.length();

        memset(dp, -1, sizeof(dp));

        return solve(0, s, n);
    }
};
