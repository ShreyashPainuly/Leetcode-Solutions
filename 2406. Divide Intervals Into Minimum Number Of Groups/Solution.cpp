// You are given a 2D integer array intervals where intervals[i] = [lefti, righti] represents the inclusive interval [lefti, righti].
// You have to divide the intervals into one or more groups such that each interval is in exactly one group, and no two intervals that are in the same group intersect each other.
// Return the minimum number of groups you need to make.
// Two intervals intersect if there is at least one common number between them. For example, the intervals [1, 5] and [5, 8] intersect.

// Example 1:
// Input: intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]
// Output: 3
// Explanation: We can divide the intervals into the following groups:
// - Group 1: [1, 5], [6, 8].
// - Group 2: [2, 3], [5, 10].
// - Group 3: [1, 10].
// It can be proven that it is not possible to divide the intervals into fewer than 3 groups.
  
// Example 2:
// Input: intervals = [[1,3],[5,6],[8,10],[11,13]]
// Output: 1
// Explanation: None of the intervals overlap, so we can put all of them in one group.

//Approach (Simply sorting and using heap)
//T.C : O(nlogn)
//S.C : O(n)

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        //Sort based on starting point
        sort(intervals.begin(), intervals.end());

        // define a minheap to store ending points of each group
        priority_queue<int, vector<int>, greater<int>> pq;

        //process each interval one by one
        for(vector<int>& interval : intervals) {
            int start = interval[0];
            int end = interval[1];

            if(!pq.empty() && start > pq.top()) {
                pq.pop();
            }

            pq.push(end);
        }

        return pq.size();
    }
};
