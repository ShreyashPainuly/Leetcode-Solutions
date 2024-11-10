// Given an integer array nums, return the length of the longest strictly increasing subsequence.
  
// Example 1:
// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

// Example 2:
// Input: nums = [0,1,0,3,2,3]
// Output: 4
  
// Example 3:
// Input: nums = [7,7,7,7,7,7,7]
// Output: 1


//Approach : Using Recursion And Memoization
//T.C : O(n*n)
//S.C : O(1)

class Solution {
public:
    int n;
    int dp[2501][2501];
    int solve(int idx, int prev, vector<int>& nums) {
        if(idx >= n) {
            return 0;
        }

        if(prev != -1 && dp[idx][prev] != -1) {
            return dp[idx][prev];
        }

        //Taking Element
        int take = 0;
        if(prev == -1 || nums[idx] > nums[prev]) {
            take = 1 + solve(idx+1, idx, nums);
        }

        //Skip Element
        int skip = solve(idx+1, prev, nums);

        if(prev != -1) {
            dp[idx][prev] = max(take, skip);
        }

        return max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, -1, nums);
    }
};
