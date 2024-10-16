// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
  
// Example 1:
// Input: s = "anagram", t = "nagaram"
// Output: true

// Example 2:
// Input: s = "rat", t = "car"
// Output: false

// Using Sorting 
// Time Complexity - O(nlogn)
// Space Complexity - O(1)

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

// Using Unordered Map
// Time Complexity - O(n)
// Space Complexity - O(n)

class Solution {
public:
    bool isAnagram(string s, string t) {

        unordered_map<char, int> count;
        
        // Count the frequency of characters in string s
        for (auto x : s) {
            count[x]++;
        }
        
        // Decrement the frequency of characters in string t
        for (auto x : t) {
            count[x]--;
        }
        
        // Check if any character has non-zero frequency
        for (auto x : count) {
            if (x.second != 0) {
                return false;
            }
        }
        return true;
    }
};
