// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
// Note that the same word in the dictionary may be reused multiple times in the segmentation.

// Example 1:
// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".

// Example 2:
// Input: s = "applepenapple", wordDict = ["apple","pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
// Note that you are allowed to reuse a dictionary word.

// Example 3:
// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: false

//Approach : Using Recursion And Memoization
//T.C : O(n*2^n)
//S.C : O(n)

class Solution {
public:
    int n;
    int dp[301];
    unordered_set<string> st;

    bool solve(int idx, string& s) {
        if(idx == n) {
            return true;
        }

        if(dp[idx] != -1) {
            return dp[idx];
        }

        if(st.find(s) != st.end()) {
            return dp[idx] = true;
        }

        for(int l = 1; l <= n; l++) {
            string temp = s.substr(idx, l);

            if(st.find(temp) != st.end() && solve(idx+l, s)) {
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }  

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();

        memset(dp, -1, sizeof(dp));

        for(string& word : wordDict) {
            st.insert(word);
        }

        return solve(0, s);
    }
};
