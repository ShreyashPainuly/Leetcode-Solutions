// You are given a string s consisting only of uppercase English letters.
// You can apply some operations to this string where, in one operation, you can remove any occurrence of one of the substrings "AB" or "CD" from s.
// Return the minimum possible length of the resulting string that you can obtain.
// Note that the string concatenates after removing the substring and could produce new "AB" or "CD" substrings.

// Example 1:
// Input: s = "ABFCACDB"
// Output: 2
// Explanation: We can do the following operations:
// - Remove the substring "ABFCACDB", so s = "FCACDB".
// - Remove the substring "FCACDB", so s = "FCAB".
// - Remove the substring "FCAB", so s = "FC".
// So the resulting length of the string is 2.
// It can be shown that it is the minimum length that we can obtain.
  
// Example 2:
// Input: s = "ACBBD"
// Output: 5
// Explanation: We cannot do any operations on the string so the length remains the same.


// Optimized Solution 1. Using Stack
//Time Complexity - O(n)
//Space Complexity - O(n)
class Solution {
public:
    int minLength(string s) {
        stack<char> st;

        for (char ch : s) {
            if (!st.empty() && ((st.top() == 'A' && ch == 'B') ||
                                (st.top() == 'C' && ch == 'D'))) {
                st.pop();
            } 
            else {
                st.push(ch);
            }
        }
        return st.size();
    }
};

// Optimized Solution 2. Using pointers i and j
//Time Complexity - O(n)
//Space Complexity - O(1)
class Solution {
public:
    int minLength(string s) {
        int n = s.length();
        
        int i = 0; //Write
        int j = 1; //Read

        while(j < n) {
            if(i < 0) {
                i++;
                s[i] = s[j];
            } else if((s[i] == 'A' && s[j] == 'B') ||
               (s[i] == 'C' && s[j] == 'D')) {
                i--;
            } else {
                i++;
                s[i] = s[j];
            }

            j++;

        }
        return i+1;
    }
};
