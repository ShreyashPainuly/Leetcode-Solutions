// You are given an array nums of non-negative integers and an integer k.
// An array is called special if the bitwise OR of all of its elements is at least k.
// Return the length of the shortest special non-empty subarray of nums, or return -1 if no special subarray exists.

// Example 1:
// Input: nums = [1,2,3], k = 2
// Output: 1
// Explanation:
// The subarray [3] has OR value of 3. Hence, we return 1.

// Example 2:
// Input: nums = [2,1,8], k = 10
// Output: 3
// Explanation:
// The subarray [2,1,8] has OR value of 11. Hence, we return 3.
  
// Example 3:
// Input: nums = [1,2], k = 0
// Output: 1
// Explanation:
// The subarray [1] has OR value of 1. Hence, we return 1.

//Approach - Simple using OR property and sliding window
//T.C : O(n)
//S.C : O(1)

class Solution {
public:
    void update(int number, vector<int>& vec, int val) {
        for(int i = 0; i < 32; i++) { //O(32)
            if((number >> i) & 1) {
                vec[i] += val;
            }
        }
    }

    int getDecimalFromBinary(vector<int>& vec) {
        int num = 0;

        for(int i = 0; i < 32; i++) { //O(32)
            if(vec[i] > 0) { //ith position me 1 hai
                num |= (1 << i);
            }
        }

        return num;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        int result = INT_MAX;

        int i = 0;
        int j = 0;

        vector<int> vec(32, 0);
        //vec[i] = total number of set bits in ith position

        
        while(j < n) { 
            update(nums[j], vec, 1); //adding in the current window

            while(i <= j && getDecimalFromBinary(vec) >= k) {
                result = min(result, j-i+1);
                update(nums[i], vec, -1); //remove the nums[i] from the window
                i++;
            }

            j++;
        }
        return result == INT_MAX ? -1 : result;
    }
};
