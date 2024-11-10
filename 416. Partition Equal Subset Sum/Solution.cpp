// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

// Example 1:
// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].
  
// Example 2:
// Input: nums = [1,2,3,5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.

//Approach : Using Recursion And Memoization
//T.C : O(n*target)
//S.C : O(n*target)

class Solution {
public:
    int n;
    bool solve(vector<int>& nums, int idx, int target, vector<vector<int>>& dp) {

        if(idx >= n) {
            return false;
        }

        if(target < 0) {
            return false;
        }

        if(target == 0) {
            return true;
        }

        if(dp[idx][target] != -1) {
            return dp[idx][target];
        }

        bool include = solve(nums, idx+1, target - nums[idx], dp);
        bool exclude = solve(nums, idx+1, target, dp);

        return dp[idx][target] = include || exclude;
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();

        int totalSum = 0;
        for(int i = 0; i < n; i++) {
            totalSum += nums[i];
        }

        if(totalSum % 2 != 0) {
            return false;
        }

        int target = totalSum / 2;

        vector<vector<int>> dp(n,vector<int>(target+1,-1));

        return solve(nums, 0, target, dp);
    }
};
