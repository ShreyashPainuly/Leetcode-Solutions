// Given an array of integers arr of even length n and an integer k.
// We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.
// Return true If you can find a way to do that or false otherwise.

// Example 1:
// Input: arr = [1,2,3,4,5,10,6,7,8,9], k = 5
// Output: true
// Explanation: Pairs are (1,9),(2,8),(3,7),(4,6) and (5,10).
  
// Example 2:
// Input: arr = [1,2,3,4,5,6], k = 7
// Output: true
// Explanation: Pairs are (1,6),(2,5) and(3,4).
  
// Example 3:
// Input: arr = [1,2,3,4,5,6], k = 10
// Output: false
// Explanation: You can try all possible pairs to see that there is no way to divide arr into 3 pairs each with sum divisible by 10.

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        // Create a map to store the frequency of each remainder
        unordered_map<int, int> remainderMap;

        // Iterate over the array and calculate the remainder of each element mod k
        for (int i = 0; i < arr.size(); ++i) {
            // Calculate the remainder (ensure it is non-negative by adding k if negative)
            int rem = arr[i] % k;
            if (rem < 0) rem += k;  // Handle negative remainders
            
            // Increment the frequency of the remainder
            remainderMap[rem]++;
        }

        // Now check if all remainders can be paired correctly
        for (auto& [rem, count] : remainderMap) {
            // Special case: remainder 0 must have an even count to pair within itself
            if (rem == 0) {
                if (count % 2 != 0) return false;
            }
            // For any remainder rem, its pair should be k - rem
            else {
                int complement = k - rem;
                // Check if the count of remainder rem matches the count of k - rem
                if (remainderMap[rem] != remainderMap[complement]) return false;
            }
        }
        return true;
    }
};
