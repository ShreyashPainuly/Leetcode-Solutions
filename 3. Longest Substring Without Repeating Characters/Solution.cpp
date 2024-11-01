// Given a string s, find the length of the longest substring without repeating characters.
  
// Example 1:
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
  
// Example 2:
// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
  
// Example 3:
// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

//Approach : Using Sliding Window
//T.C : O(n)
//S.C : O(n)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        set<char> st;
        
        int maxLen = 0;

        int start = 0; 
        int end = 0;

        while(end < n) {
            auto it = st.find(s[end]);
            if(it == st.end()) {
                if(end - start + 1 > maxLen) {
                    maxLen = end - start + 1;
                }
                st.insert(s[end]);
                end++;
            }
            else {
                st.erase(s[start]);
                start++;
            }
        }
        return maxLen;
    }
};
