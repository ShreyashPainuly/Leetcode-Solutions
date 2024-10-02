// Given an array of integers arr, replace each element with its rank.
// The rank represents how large the element is. The rank has the following rules:
// Rank is an integer starting from 1.
// The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
// Rank should be as small as possible.
 
// Example 1:
// Input: arr = [40,10,20,30]
// Output: [4,1,2,3]
// Explanation: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 30 is the third smallest.

// Example 2:
// Input: arr = [100,100,100]
// Output: [1,1,1]
// Explanation: Same elements share the same rank.
  
// Example 3:
// Input: arr = [37,12,28,9,100,56,80,5,12]
// Output: [5,3,4,2,8,6,7,1,3]

//Non - Optimized Approach
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int> mp;
        // store values in ordered map
        for(auto& val: arr){
            mp[val]++;
        }

        // start assign value their rank 
        // from top to bottom
        int rank=1;
        for(auto& val:mp){
            val.second = rank;
            rank++;
        }

        // traverse on array and assign them
        // rank based on map
        vector<int> ans(arr.size());
        for(int i=0;i<arr.size();i++){
            ans[i] = mp[arr[i]];
        }

        // return the ranks
        return ans;
    }
};

//Optimized Approach
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
         // create a copy of arr
        vector<int> arr_copy = arr;

        // sort it
        sort(arr_copy.begin(), arr_copy.end());

        // assign rank from front 
        int rank = 1;
        // store it in map
        unordered_map<int,int> um;
        for(int i=0;i<arr_copy.size();i++){
            // check if the element is already present
            // (avoid duplicate rank to same number)
            if(um.find(arr_copy[i]) == um.end()){
                um[arr_copy[i]] = rank;
                rank++;
            }
        }

        // traverse on array and assign them
        // rank based on map
        vector<int> ans(arr.size());
        for(int i=0;i<arr.size();i++){
            ans[i] = um[arr[i]];
        }

        // return the ranks
        return ans;
    }
};
