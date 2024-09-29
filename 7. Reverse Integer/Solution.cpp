// Example 1:

// Input: x = 123
// Output: 321
// Example 2:

// Input: x = -123
// Output: -321
// Example 3:

// Input: x = 120
// Output: 21

class Solution {
public:
    int reverse(int x) {
        int reversedNo = 0;
        while(x != 0) {
            if(reversedNo > INT_MAX/10 || reversedNo < INT_MIN/10) {
                return 0;
            }
            reversedNo = reversedNo * 10 + x % 10;
            x = x / 10;
        }
        return reversedNo;
    }
};
