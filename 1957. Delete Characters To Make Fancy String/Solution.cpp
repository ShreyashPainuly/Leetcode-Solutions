// A fancy string is a string where no three consecutive characters are equal.
// Given a string s, delete the minimum possible number of characters from s to make it fancy.
// Return the final string after the deletion. It can be shown that the answer will always be unique.

// Example 1:
// Input: s = "leeetcode"
// Output: "leetcode"
// Explanation:
// Remove an 'e' from the first group of 'e's to create "leetcode".
// No three consecutive characters are equal, so return "leetcode".
  
// Example 2:
// Input: s = "aaabaaaa"
// Output: "aabaa"
// Explanation:
// Remove an 'a' from the first group of 'a's to create "aabaaaa".
// Remove two 'a's from the second group of 'a's to create "aabaa".
// No three consecutive characters are equal, so return "aabaa".
  
// Example 3:
// Input: s = "aab"
// Output: "aab"
// Explanation: No three consecutive characters are equal, so return "aab".

//Approach : Simple Basic Understanding
//T.C : O(n)
//S.C : O(1)

class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        
        string result = "";
        result.push_back(s[0]);
        int freq = 1;

        for(int i = 1; i<n; i++) {
            if(s[i] == result.back()) {
                freq++;
                if(freq < 3) {
                    result.push_back(s[i]);
                }
            }
            else {
                result.push_back(s[i]);
                freq = 1;
            }
        }
        return result;
    }
};
