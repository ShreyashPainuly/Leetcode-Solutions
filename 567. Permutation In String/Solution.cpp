// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
// In other words, return true if one of s1's permutations is the substring of s2.

// Example 1:
// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").
  
// Example 2:
// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        // Is s1 is longer than s2, it cannot be a substring
        if(n > m) {
            return false;
        }

        // Sort the string s1
        string sorted_s1 = s1;
        sort(sorted_s1.begin(), sorted_s1.end());

        // Iterate over each substring of s2
        for(int i = 0; i <= m; i++) {
            // Extract the substring of length n from s2 starting at index i
            string temp = s2.substr(i, n);

            // Sort the substring temp
            sort(temp.begin(), temp.end());

            // If temp is equal to sorted s1 then return true;
            if(temp == sorted_s1) {
                return true;
            }

        }
        // No permutation found in s2
        return false;
    }
};
