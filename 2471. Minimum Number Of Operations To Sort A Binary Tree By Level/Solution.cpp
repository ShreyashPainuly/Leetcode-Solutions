// You are given the root of a binary tree with unique values.
// In one operation, you can choose any two nodes at the same level and swap their values.
// Return the minimum number of operations needed to make the values at each level sorted in a strictly increasing order.
// The level of a node is the number of edges along the path between it and the root node.

// Example 1:
// Input: root = [1,4,3,7,6,8,5,null,null,null,null,9,null,10]
// Output: 3
// Explanation:
// - Swap 4 and 3. The 2nd level becomes [3,4].
// - Swap 7 and 5. The 3rd level becomes [5,6,8,7].
// - Swap 8 and 7. The 3rd level becomes [5,6,7,8].
// We used 3 operations so return 3.
// It can be proven that 3 is the minimum number of operations needed.
  
// Example 2:
// Input: root = [1,3,2,7,6,5,4]
// Output: 3
// Explanation:
// - Swap 3 and 2. The 2nd level becomes [2,3].
// - Swap 7 and 4. The 3rd level becomes [4,6,5,7].
// - Swap 6 and 5. The 3rd level becomes [4,5,6,7].
// We used 3 operations so return 3.
// It can be proven that 3 is the minimum number of operations needed.


//Approach - Simple BFS with hidden problem
//T.C : O(n + level * wlogw), level = total levels, w = number of nodes in a level
//S.C : O(n)
class Solution {
public:
    int countMinSwapsToSort(vector<int>& vec) {
        int swaps = 0;
        vector<int> sortedVec(begin(vec), end(vec));
        
        sort(begin(sortedVec), end(sortedVec));

        unordered_map<int, int> mp; //nums[i] -> i
        for(int i = 0; i < vec.size(); i++) {
            mp[vec[i]] = i;
        }

        for(int i = 0; i < vec.size(); i++) {
            if(vec[i] == sortedVec[i])
                continue; //no swap required
            
            int currIdx = mp[sortedVec[i]];
            mp[vec[i]] = currIdx;
            mp[vec[currIdx]] = i;
            swap(vec[currIdx], vec[i]);
            swaps++;
        }

        return swaps;
    }

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);

        int result = 0;

        while(!que.empty()) {
            int n = que.size(); //total nodes in current level
            vector<int> vec;

            while(n--) {
                TreeNode* temp = que.front();
                que.pop();
                vec.push_back(temp->val);

                if(temp->left) {
                    que.push(temp->left);
                }

                if(temp->right) {
                    que.push(temp->right);
                }
            }

            result += countMinSwapsToSort(vec);
        }

        return result;
    }
};
