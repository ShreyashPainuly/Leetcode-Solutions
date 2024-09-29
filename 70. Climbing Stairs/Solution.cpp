// Example 1:
// Input: n = 2
// Output: 2

// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps

// Example 2:
// Input: n = 3
// Output: 3

// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step

class Solution {
public:
    int climbStairs(int n) {
        // Using Space optimization
        if (n == 0 || n == 1) {
            return 1;
        }

        int previous = 1;
        int current = 1;
        for (int i = 2; i <= n; i++) {
            int temp = current;
            current = previous + current;
            previous = temp;
        }
        return current;
    }
};
