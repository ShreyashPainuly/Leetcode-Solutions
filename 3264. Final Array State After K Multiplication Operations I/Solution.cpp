// You are given an integer array nums, an integer k, and an integer multiplier.
// You need to perform k operations on nums. In each operation:
// Find the minimum value x in nums. If there are multiple occurrences of the minimum value, select the one that appears first.
// Replace the selected minimum value x with x * multiplier.
// Return an integer array denoting the final state of nums after performing all k operations.

// Example 1:
// Input: nums = [2,1,3,5,6], k = 5, multiplier = 2
// Output: [8,4,6,5,6]
// Explanation:
// Operation	Result
// After operation 1	[2, 2, 3, 5, 6]
// After operation 2	[4, 2, 3, 5, 6]
// After operation 3	[4, 4, 3, 5, 6]
// After operation 4	[4, 4, 6, 5, 6]
// After operation 5	[8, 4, 6, 5, 6]


//Approach-1 (Brute Force)
//T.C : O(n * k)
//S.C : O(1)
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();

        for (int j = 0; j < k; j++) {

            int idx = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] < nums[idx]) {
                    idx = i;
                }
            }

            nums[idx] *= multiplier;
        }

        return nums;
    }
};


//Approach-2 (Using stl::priority_queue)
//T.C : O(nlogn + klogn)
//S.C : O(n)
class Solution {
public:
    #define P pair<int, int>
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();

        priority_queue<P, vector<P>, greater<P>> pq;
        for(int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        while(k--) {
            pair<int, int> temp = pq.top();
            pq.pop();

            int idx = temp.second;
            int number = temp.first;

            nums[idx] = number*multiplier;

            pq.push({nums[idx], idx});
        }

        return nums;
    }
};


//Approach-3 (Using vector as heap for O(n) heapify)
//T.C : O(n + klogn)
//S.C : O(n)
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();

        vector<pair<int, int>> vec(n);
        for(int i = 0; i < n; i++) {
            vec[i] = {nums[i], i};
        }

        make_heap(begin(vec), end(vec), greater<>());

        while(k--) {
            pop_heap(begin(vec), end(vec), greater<>());
            pair<int, int> temp = vec.back();
            vec.pop_back();

            int idx = temp.second;
            int number = temp.first;

            nums[idx] = number*multiplier;

            vec.push_back({nums[idx], idx});
            push_heap(begin(vec), end(vec), greater<>());
        }

        return nums;
    }
};
