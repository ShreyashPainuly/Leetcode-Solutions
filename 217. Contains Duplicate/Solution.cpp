Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true
Explanation:
The element 1 occurs at the indices 0 and 3.
  
Example 2:
Input: nums = [1,2,3,4]
Output: false
Explanation:
All elements are distinct.

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

// Using Unordered Map
// Time Complexity - O(n)
// Space Complexity - O(n)
  
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> count;

        for(auto x : nums) {
            count[x]++;
        }

        for(auto x : count) {
            if(x.second > 1) {
                return true;
            }
        }
        return false;
    }
};
