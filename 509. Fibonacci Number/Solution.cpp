// The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
// F(0) = 0, F(1) = 1
// F(n) = F(n - 1) + F(n - 2), for n > 1.
// Given n, calculate F(n).

// Example 1:
// Input: n = 2
// Output: 1
// Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
  
// Example 2:
// Input: n = 3
// Output: 2
// Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
  
// Example 3:
// Input: n = 4
// Output: 3
// Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.

// Recursion Approach:
// Time Complexity: O(2^n)
// Space Complexity: O(1)

class Solution {
public:
    int fib(int n) {
        if(n <= 1){
            return n;
        }
        else {
            return fib(n-1) + fib(n-2);
        }
    }
};

// Recursion and Memoization Approach:
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if(n <= 1) {
            return n;
        }

        if(dp[n] != -1) {
            return dp[n];
        }

        return dp[n] = solve(n-1, dp) + solve(n-2, dp);
    }
    int fib(int n) {

        //Base Case
        if(n <= 1) {
            return n;
        }

        vector<int> dp(n+1, -1);

        return solve(n, dp);
    }
};

// DP Bottom - up Approach:
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int fib(int n) {
        //Base Case
        if(n <= 1) {
            return n;
        }

        vector<int> dp(n+1, -1);

        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};

// Constant Space Approach:
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int fib(int n) {
        //Base Case
        if(n <= 1) {
            return n;
        }

        int a = 0;
        int b = 1;
        int c;

        for(int i = 1; i<n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

