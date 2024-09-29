// Example 1:
// Input: nums = [1,2,3,3,2,2]
// Output: 2
// Explanation:
// The maximum possible bitwise AND of a subarray is 3.
// The longest subarray with that value is [3,3], so we return 2.

// Example 2:
// Input: nums = [1,2,3,4]
// Output: 1
// Explanation:
// The maximum possible bitwise AND of a subarray is 4.
// The longest subarray with that value is [4], so we return 1.

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //finding the maximum element from the array
        int maxi = 0;
        for(int n:nums) {
            maxi = max(maxi, n);
        }

        int length = 0;
        int ans = 0;
        for(int n:nums) {
            if(n == maxi) {
                length++;
                ans = max(ans, length);
            }
            else {
                length = 0;
            }
        }
        return ans;
    }    
};
