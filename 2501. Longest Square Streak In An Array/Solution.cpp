// You are given an integer array nums. A subsequence of nums is called a square streak if:
// The length of the subsequence is at least 2, and
// after sorting the subsequence, each element (except the first element) is the square of the previous number.
// Return the length of the longest square streak in nums, or return -1 if there is no square streak.
// A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

// Example 1:
// Input: nums = [4,3,6,16,8,2]
// Output: 3
// Explanation: Choose the subsequence [4,16,2]. After sorting it, it becomes [2,4,16].
// - 4 = 2 * 2.
// - 16 = 4 * 4.
// Therefore, [4,16,2] is a square streak.
// It can be shown that every subsequence of length 4 is not a square streak.
  
// Example 2:
// Input: nums = [2,3,5,6,7]
// Output: -1
// Explanation: There is no square streak in nums so return -1.

//Approach-1 (Using sorting and map)
//T.C : O(nlogn)
//S.C : O(n)

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int, int> mp;

        sort(begin(nums), end(nums));

        int maxStreak = 0;

        for(int &num : nums) { //2, 4 
            //check if this number is a perfect square
            int root = (int)sqrt(num);

            if(root*root == num && mp.find(root) != mp.end()) {
                mp[num] = mp[root] + 1;
            } else {
                mp[num] = 1;
            }

            maxStreak = max(maxStreak, mp[num]);

        }

        return maxStreak < 2 ? -1 : maxStreak;
    }
};

//Approach-2 (Using set)
//T.C : O(n) ///Note : O(n) because while loop will run max 5 times. So if constraint is given, then saying O(n) time complexity is fine.
//S.C : O(n)

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> st(begin(nums), end(nums));

        int maxStreak = 0;

        for (int& num : nums) {
            int streak = 0;
            long long curr = num;

            while (st.find(curr) != st.end()) {
                streak++;

                if (curr * curr > 1e5) {
                    break;
                }

                curr = curr * curr; // square
            }

            maxStreak = max(maxStreak, streak);
        }

        return maxStreak < 2 ? -1 : maxStreak;
    }
};
