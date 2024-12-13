You are given an array nums consisting of positive integers.
Starting with score = 0, apply the following algorithm:
Choose the smallest integer of the array that is not marked. If there is a tie, choose the one with the smallest index.
Add the value of the chosen integer to score.
Mark the chosen element and its two adjacent elements if they exist.
Repeat until all the array elements are marked.
Return the score you get after applying the above algorithm.

Example 1:
Input: nums = [2,1,3,4,5,2]
Output: 7
Explanation: We mark the elements as follows:
- 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,1,3,4,5,2].
- 2 is the smallest unmarked element, so we mark it and its left adjacent element: [2,1,3,4,5,2].
- 4 is the only remaining unmarked element, so we mark it: [2,1,3,4,5,2].
Our score is 1 + 2 + 4 = 7.

Example 2:
Input: nums = [2,3,5,1,3,2]
Output: 5
Explanation: We mark the elements as follows:
- 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,3,5,1,3,2].
- 2 is the smallest unmarked element, since there are two of them, we choose the left-most one, so we mark the one at index 0 and its right adjacent element: [2,3,5,1,3,2].
- 2 is the only remaining unmarked element, so we mark it: [2,3,5,1,3,2].
Our score is 1 + 2 + 2 = 5.

//Approach-1 (Sorting array with indices)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> vec(n);

        for(int i = 0; i < n; i++) {
            vec[i] = {nums[i], i};
        }

        sort(begin(vec), end(vec)); //O(nlogn)

        long long score = 0;
        vector<bool> visited(n, false);

        for(int i = 0; i < n; i++) { //O(n)
            int element = vec[i].first;
            int idx     = vec[i].second;
            if(visited[idx] == false) {
                visited[idx] = true;
                score += element;

                if(idx-1 >= 0 && visited[idx-1] == false) {
                    visited[idx-1] = true;
                }
                if(idx+1 < n && visited[idx+1] == false) {
                    visited[idx+1] = true;
                }
            }
        }

        return score;
    }
};



//Approach-2 (Using min-heap)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    #define P pair<int, int>
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);

        priority_queue<P, vector<P>, greater<P>> pq;
        for(int i = 0; i < n; i++) {//n
            pq.push({nums[i], i}); //log(n)
        }

        long long score = 0;
        while(!pq.empty()) { //n
            P temp = pq.top();
            int element = temp.first;
            int idx = temp.second;
            pq.pop(); //log(n)

            if(!visited[idx]) {
                visited[idx] = true;
                score += element;

                if(idx-1 >= 0 && !visited[idx-1]) {
                    visited[idx-1] = true;
                }
                if(idx+1 < n && !visited[idx+1]) {
                    visited[idx+1] = true;
                }
            }
        }

        return score;
    }
};
