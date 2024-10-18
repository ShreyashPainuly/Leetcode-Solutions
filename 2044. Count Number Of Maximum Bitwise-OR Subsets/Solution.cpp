// Given an integer array nums, find the maximum possible bitwise OR of a subset of nums and return the number of different non-empty subsets with the maximum bitwise OR.
// An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b. Two subsets are considered different if the indices of the elements chosen are different.
// The bitwise OR of an array a is equal to a[0] OR a[1] OR ... OR a[a.length - 1] (0-indexed).

// Example 1:
// Input: nums = [3,1]
// Output: 2
// Explanation: The maximum possible bitwise OR of a subset is 3. There are 2 subsets with a bitwise OR of 3:
// - [3]
// - [3,1]
  
// Example 2:
// Input: nums = [2,2,2]
// Output: 7
// Explanation: All non-empty subsets of [2,2,2] have a bitwise OR of 2. There are 23 - 1 = 7 total subsets.
  
// Example 3:
// Input: nums = [3,2,1,5]
// Output: 6
// Explanation: The maximum possible bitwise OR of a subset is 7. There are 6 subsets with a bitwise OR of 7:
// - [3,5]
// - [3,1,5]
// - [3,2,5]
// - [3,2,1,5]
// - [2,5]
// - [2,1,5]

//Approach - Memoizing to store subproblems result
//T.C : O(n*maxOr)
//S.C : O(1)

class Solution {
public:
    int countSubsets(int index, int currOR, vector<int>& nums, int maxOR,
                     vector<vector<int>>& t) {
        // Base Case
        if (index == nums.size()) {
            if (currOR == maxOR) {
                return 1;
            } else {
                return 0;
            }
        }

        if (t[index][currOR] != -1) {
            return t[index][currOR];
        }

        // Taking nums[index]
        int takeCount =
            countSubsets(index + 1, currOR | nums[index], nums, maxOR, t);

        // Not Taking nums[index]
        int notTakeCount = countSubsets(index + 1, currOR, nums, maxOR, t);

        return t[index][currOR] = takeCount + notTakeCount;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOR = 0;

        for (int i = 0; i < n; i++) {
            maxOR |= nums[i];
        }

        vector<vector<int>> t(n + 1, vector<int>(maxOR + 1, -1));

        int currOR = 0;
        return countSubsets(0, currOR, nums, maxOR, t);
    }
};
