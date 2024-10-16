// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

// Example 1:
// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
  
// Example 2:
// Input: nums = [1], k = 1
// Output: [1]

//Approach - (Using min-heap) 
// TC : O(nlog(k))

class Solution {
public:
    typedef pair<int, int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //Step 1. Define Map and store Freqencies
        unordered_map<int, int> mp;
        for(auto &x : nums) {
            mp[x]++;
        }

        //Define min-heap
        priority_queue<P, vector<P>, greater<P>> pq;

        //Push Elements in min-heap {freq, element}
        //maintain size of pq

        for(auto &it : mp) {
            int value = it.first;
            int freq = it.second;

            pq.push({freq, value});

            if(pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> result;

        while(!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();      
        }
        return result;
    }
};
