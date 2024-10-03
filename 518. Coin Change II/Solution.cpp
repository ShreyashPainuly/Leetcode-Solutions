// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
// Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
// You may assume that you have an infinite number of each kind of coin.
// The answer is guaranteed to fit into a signed 32-bit integer.
 
// Example 1:
// Input: amount = 5, coins = [1,2,5]
// Output: 4
// Explanation: there are four ways to make up the amount:
// 5=5
// 5=2+2+1
// 5=2+1+1+1
// 5=1+1+1+1+1
  
// Example 2:
// Input: amount = 3, coins = [2]
// Output: 0
// Explanation: the amount of 3 cannot be made up just with coins of 2.

// Example 3:
// Input: amount = 10, coins = [10]
// Output: 1

class Solution {
    int n;
    int t[301][5001];
private:
    int solve(int index, vector<int>& coins, int amount) {
        if(amount == 0) {
            return 1;
        }

        if(index == n) {
            return 0;
        }

        if(t[index][amount] != -1) {
            return t[index][amount];
        }

        if(coins[index] > amount) {
            return t[index][amount] = solve(index + 1, coins, amount);
        }

        int take = solve(index, coins, amount - coins[index]);
        int skip = solve(index + 1, coins, amount);

        return t[index][amount] = take + skip;
    }

public:
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        memset(t, -1, sizeof(t));
        return solve(0, coins, amount);
    }
};
