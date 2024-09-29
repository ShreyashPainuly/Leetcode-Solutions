// Example 1:
// Input: x = 121
// Output: true
// Explanation: 121 reads as 121 from left to right and from right to left.

// Example 2:
// Input: x = -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

// Example 3:
// Input: x = 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

class Solution {
public:

    int reverseNo(int x) {
        int reversedigit= 0;
        while(x > 0) {
            if(reversedigit > INT_MAX/10 || reversedigit < INT_MIN/10) {
                return 0;
            }
            reversedigit = reversedigit * 10 + x % 10;
            x = x / 10;
        }
        return reversedigit;
    }

    bool isPalindrome(int x) {
        int ans = reverseNo(x);
        if(x == ans) {
            return true;
        }
        else {
            return false;
        }
    }
};
