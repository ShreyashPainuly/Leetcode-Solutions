// Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.
// A pair (i, j) is fair if: 
// -> 0 <= i < j < n, and
// -> lower <= nums[i] + nums[j] <= upper
    
// Example 1:
// Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
// Output: 6
// Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).

// Example 2:
// Input: nums = [1,7,9,2,5], lower = 11, upper = 11
// Output: 1
// Explanation: There is a single fair pair: (2,3).

//Approach (simple binary search trick)
//T.C : O(nlogn)
//S.C : O(1)

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        sort(begin(nums), end(nums)); // nlogn

        long long result = 0;

        for (int i = 0; i < n; i++) { // O(n * logn)
            // o(n)
            int idx =
                lower_bound(begin(nums) + i + 1, end(nums), lower - nums[i]) -
                begin(nums); // Gives the firstc element NOT LESS than (lower -
                             // nums[i]) //log(n)
            int x = idx - 1 - i;

            idx = upper_bound(begin(nums) + i + 1, end(nums), upper - nums[i]) -
                  begin(nums); // Gives the firstc element GREATER than (upper -
                               // nums[i]) //log(n)

            int y = idx - 1 - i;

            result += (y - x);
        }

        return result;
    }
};