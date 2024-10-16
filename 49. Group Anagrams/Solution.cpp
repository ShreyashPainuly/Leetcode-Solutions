// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// Example 1:
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// Explanation:
// There is no string in strs that can be rearranged to form "bat".
// The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
// The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

// Example 2:
// Input: strs = [""]
// Output: [[""]]
  
// Example 3:
// Input: strs = ["a"]
// Output: [["a"]]

//Approach-2 (Without Sorting)
//T.C : O(n*k)  (n = size of input, k = maximum length of a string in the input vector)
//S.C : O(n*k)

class Solution {
public:
    string generate(string& word) {
        int arr[26] = {0};
        for(char ch : word) {
            arr[ch - 'a']++;
        }

        string new_word = "";

        for(int i = 0; i < 26; i++) {
            if(arr[i] > 0) {
                new_word += string(arr[i], i + 'a');
            }
        }
        return new_word;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> mp;

        vector<vector<string>> result;

        for(int i = 0; i < n; i++) {
            string word = strs[i];
            string new_word = generate(word);

            mp[new_word].push_back(word);
        }

        for(auto &it : mp) {
            result.push_back(it.second);
        }
        return result;
    }
};
