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
