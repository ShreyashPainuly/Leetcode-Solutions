// You are given the root of a binary tree with n nodes. Each node is assigned a unique value from 1 to n. You are also given an array queries of size m.
// You have to perform m independent queries on the tree where in the ith query you do the following:
// Remove the subtree rooted at the node with the value queries[i] from the tree. It is guaranteed that queries[i] will not be equal to the value of the root.
// Return an array answer of size m where answer[i] is the height of the tree after performing the ith query.
// Note:
// The queries are independent, so the tree returns to its initial state after each query.
// The height of a tree is the number of edges in the longest simple path from the root to some node in the tree.

// Example 1:
// Input: root = [1,3,4,2,null,6,5,null,null,null,null,null,7], queries = [4]
// Output: [2]
// Explanation: The diagram above shows the tree after removing the subtree rooted at node with value 4.
// The height of the tree is 2 (The path 1 -> 3 -> 2).
  
// Example 2:
// Input: root = [5,8,9,2,1,3,7,4,6], queries = [3,2,4,8]
// Output: [3,2,3,2]
// Explanation: We have the following queries:
// - Removing the subtree rooted at node with value 3. The height of the tree becomes 3 (The path 5 -> 8 -> 2 -> 4).
// - Removing the subtree rooted at node with value 2. The height of the tree becomes 2 (The path 5 -> 8 -> 1).
// - Removing the subtree rooted at node with value 4. The height of the tree becomes 3 (The path 5 -> 8 -> 2 -> 6).
// - Removing the subtree rooted at node with value 8. The height of the tree becomes 2 (The path 5 -> 9 -> 3).

//Approach - Simple Recursion and preprocessing
//T.C : O(n)
//S.C : O(n)

class Solution {
public:
    int level[1000001]; // level of each node
    int height[100001]; // height of each node
    int levelMaxHt[100001];
    int levelSecondMaxHt[100001];

    int findHeight(TreeNode* root, int l) {
        if (!root) {
            return 0;
        }

        level[root->val] = l;
        height[root->val] =
            max(findHeight(root->left, l + 1), findHeight(root->right, l + 1)) +
            1;

        if (levelMaxHt[l] < height[root->val]) {
            levelSecondMaxHt[l] = levelMaxHt[l];
            levelMaxHt[l] = height[root->val];
        } else if (levelSecondMaxHt[l] < height[root->val]) {
            levelSecondMaxHt[l] = height[root->val];
        }

        return height[root->val];
    }
    
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        findHeight(root, 0);

        vector<int> result;

        for (int& node : queries) {
            // node = that we have to delete
            int L = level[node]; // O(1) //node ka level hai ye

            // L + H - 1

            int tempResult =
                L +
                (levelMaxHt[L] == height[node] ? levelSecondMaxHt[L]
                                               : levelMaxHt[L]) -
                1;

            result.push_back(tempResult);
        }
        return result;
    }
};