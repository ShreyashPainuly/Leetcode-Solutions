// You are given an array of integers nums of length n and a positive integer k.
// The power of an array is defined as:
// -> Its maximum element if all of its elements are consecutive and sorted in ascending order.
// -> -1 otherwise.
// You need to find the power of all subarrays of nums of size k.
// Return an integer array results of size n - k + 1, where results[i] is the power of nums[i..(i + k - 1)].

// Example 1:
// Input: nums = [1,2,3,4,3,2,5], k = 3
// Output: [3,4,-1,-1,-1]
// Explanation:
// There are 5 subarrays of nums of size 3:
// [1, 2, 3] with the maximum element 3.
// [2, 3, 4] with the maximum element 4.
// [3, 4, 3] whose elements are not consecutive.
// [4, 3, 2] whose elements are not sorted.
// [3, 2, 5] whose elements are not consecutive.
  
// Example 2:
// Input: nums = [2,2,2,2,2], k = 4
// Output: [-1,-1]
  
// Example 3:
// Input: nums = [3,2,3,2,3,2], k = 2
// Output: [-1,3,-1,3,-1]

//Approach-1 (Using sliding window)
//T.C : O(n)
//S.C : O(1)

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> result(n-k+1, -1);

        int count = 1; //count of consecutive elements

        //preprocess the first window
        for(int i = 1; i < k; i++) {
            if(nums[i] == nums[i-1]+1) {
                count++;
            } else {
                count = 1;
            }
        }

        if(count == k) {
            result[0] = nums[k-1];
        }

        int i = 1;
        int j = k;

        while(j < n) {
            if(nums[j] == nums[j-1]+1) {
                count++;
            } else {
                count = 1;
            }

            if(count >= k) {
                result[i] = nums[j];
            }

            i++;
            j++;
        }

        return result;

    }
};


//Approach-2 (Using monotonic deque)
//T.C : O(n)
//S.C : O(n)

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> deq; //Monotonic deque
        vector<int> result;

        for(int j = 0; j < n; j++) {

            if(deq.size() == k) {
                deq.pop_front(); //deq ka size ab k-1, ab jth element ko hum insert karne ka soch sakte hain deque me
            }

            if(!deq.empty() && deq.back() != nums[j]-1) { //nums[j] is not consecutive to deq.back() element
                deq.clear();
            }

            deq.push_back(nums[j]);

            if(j >= k-1) {
                if(deq.size() == k) {
                    result.push_back(deq.back()); //max element hoga becau monotonic hai
                } else {
                    result.push_back(-1); //else -1
                }
            }
        }

        return result;
    }
};
