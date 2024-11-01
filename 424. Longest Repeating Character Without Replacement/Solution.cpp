// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
// Return the length of the longest substring containing the same letter you can get after performing the above operations.

// Example 1:
// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.
  
// Example 2:
// Input: s = "AABABBA", k = 1
// Output: 4class Solution {

// Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.
// There may exists other ways to achieve this answer too.

//Approach : Using Sliding Window
//T.C : O(n)
//S.C : O(26)

public:
    int characterReplacement(string s, int k) {
        int n = s.length();

        int hashMap[26] = {0};

        int start = 0;
        int end = 0;

        int maxFreq = 0;
        int maxLen = 0;

        while(end < n) {
            hashMap[s[end]-'A']++;
            if(hashMap[s[end]-'A'] > maxFreq) {
                maxFreq = max(maxFreq, hashMap[s[end]-'A']);
            }

            if(end - start + 1 - maxFreq > k) {
                hashMap[s[start]-'A']--;
                start++;
            }
            maxLen = max(maxLen, end - start + 1);
            end++;
        }
        return maxLen;
    }
};
