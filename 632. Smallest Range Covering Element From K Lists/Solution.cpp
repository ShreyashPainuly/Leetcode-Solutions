// You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.
// We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

// Example 1:
// Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
// Output: [20,24]
// Explanation: 
// List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
// List 2: [0, 9, 12, 20], 20 is in range [20,24].
// List 3: [5, 18, 22, 30], 22 is in range [20,24].
  
// Example 2:
// Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
// Output: [1,1]

//Approach-1 (Using vector of indexes)
//T.C : O(n*k)
//S.C : O(k)

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

        vector<int> vec(k, 0);
        vector<int> resultRange = {-1000000, 1000000};

        while(true) {
            int minElement = INT_MAX;
            int maxElement = INT_MIN;
            int minElementListIndex = 0;

            for(int i = 0; i < k; i++) {
                int listIndex = i;
                int elementIndex = vec[i];
                int element = nums[listIndex][elementIndex];

                if(element < minElement) {
                    minElement = element;
                    minElementListIndex = listIndex;
                }

                maxElement = max(maxElement, element);
            }
            //Range - (minElement, maxElement)
            if(maxElement - minElement < resultRange[1] - resultRange[0]) {
                resultRange[0] = minElement;
                resultRange[1] = maxElement;
            }

            //now shorten this range by moving minElement index
            int nextIndex = vec[minElementListIndex] + 1;
            if(nextIndex >= nums[minElementListIndex].size()) {
                break;
            }
            vec[minElementListIndex] = nextIndex;
        }
        return resultRange;
    }
};

//Approach-2 (Using heap)
//T.C : O(n*log(k))
//S.C : O(k)
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

        //{element, listIdx, idx} //vector<int>{a, b, c}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        int maxEl = INT_MIN;
        for(int i = 0; i < k; i++) {
            pq.push({nums[i][0], i, 0});
            maxEl = max(maxEl, nums[i][0]);
        }

        vector<int> resultRange = {-1000000, 1000000};

        while(!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();

            int minEl = curr[0];
            int listIdx = curr[1];
            int idx     = curr[2];

            if(maxEl - minEl < resultRange[1] -  resultRange[0]) {
                resultRange[0] = minEl;
                resultRange[1] = maxEl;
            }

            //decrease the rangen fro minimums ide
            if(idx+1 < nums[listIdx].size()) {
                int nextElement = nums[listIdx][idx+1];
                pq.push({nextElement, listIdx, idx+1});
                maxEl = max(maxEl, nextElement);
            } else {
                break;
            }
        }

        return resultRange;
    }
};
