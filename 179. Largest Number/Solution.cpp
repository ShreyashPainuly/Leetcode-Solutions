// Example 1:
// Input: nums = [10,2]
// Output: "210"
  
// Example 2:
// Input: nums = [3,30,34,5,9]
// Output: "9534330"

bool compare(int a, int b) {
    string sa = to_string(a);
    string sb = to_string(b);

    // Custom comparison to check which concatenation is larger
    if((sa + sb )> (sb + sa)){
        return true;
    }
    return false;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Sort using the custom comparator
        sort(nums.begin(), nums.end(), compare);

        // If the largest number after sorting is '0', the result is "0"
        if (nums[0] == 0) {
            return "0";
        }

        string ans = "";
        for (int num : nums) {
            ans += to_string(num);
        }

        return ans;
    }
};
