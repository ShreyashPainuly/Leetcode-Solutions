// Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

// Example 1:
// Input: c = 5
// Output: true
// Explanation: 1 * 1 + 2 * 2 = 5
  
// Example 2:
// Input: c = 3
// Output: false

// Optimized Brute Force Approach:
// Time complexity: O(sqrt(c))
// Space Complexity: O(1)

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long long a = 0; a * a <= c; a++) {
            long long b = sqrt(c - a * a);
            if (a * a + b * b == c) {
                return true;
            }
        }
        return false;
    }
};
