// You are given the root of a binary tree and a positive integer k.
// The level sum in the tree is the sum of the values of the nodes that are on the same level.
// Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.
// Note that two nodes are on the same level if they have the same distance from the root.

// Example 1:
// Input: root = [5,8,9,2,1,3,7,4,6], k = 2
// Output: 13
// Explanation: The level sums are the following:
// - Level 1: 5.
// - Level 2: 8 + 9 = 17.
// - Level 3: 2 + 1 + 3 + 7 = 13.
// - Level 4: 4 + 6 = 10.
// The 2nd largest level sum is 13.

// Example 2:
// Input: root = [1,2,null,3], k = 1
// Output: 3
// Explanation: The largest level sum is 3.

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long, vector<long>, greater<long>> pq; // Min Heap

        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int n = que.size();
            long levelSum = 0;
            while (n--) {
                TreeNode* poppedNode = que.front();
                que.pop();
                levelSum += poppedNode->val;
                if (poppedNode->left != NULL) {
                    que.push(poppedNode->left);
                }
                if (poppedNode->right != NULL) {
                    que.push(poppedNode->right);
                }
            }

            pq.push(levelSum);

            if (pq.size() > k) {
                pq.pop();
            }
        }

        return pq.size() < k ? -1 : pq.top();
    }
};
