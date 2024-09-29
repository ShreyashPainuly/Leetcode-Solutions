// Example 1:
// Input: s1 = "this apple is sweet", s2 = "this apple is sour"
// Output: ["sweet","sour"]

// Explanation:
// The word "sweet" appears only in s1, while the word "sour" appears only in s2.

// Example 2:
// Input: s1 = "apple apple", s2 = "banana"
// Output: ["banana"]

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string s = s1 + " " + s2;
        stringstream str(s);
        unordered_map<string, int> mp;
        string word;
        while(str >> word) {
            mp[word]++;
        }

        vector<string> ans;
        for(auto x:mp) {
            if(x.second == 1) {
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};
