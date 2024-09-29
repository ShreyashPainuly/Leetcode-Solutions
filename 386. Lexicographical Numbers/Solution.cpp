// Example 1:
// Input: n = 13
// Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
  
// Example 2:
// Input: n = 2
// Output: [1,2]

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> s;
        for(int i = 1; i<=n; i++) {
            string temp = to_string(i);
            s.push_back(temp);
        }
        sort(s.begin(), s.end());

        vector<int> ans;
        for(auto x:s) {
            ans.push_back(stoi(x));
        }
        return ans;
    }
};
