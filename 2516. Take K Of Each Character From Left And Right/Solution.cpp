// You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k. Each minute, you may take either the leftmost character of s, or the rightmost character of s.
// Return the minimum number of minutes needed for you to take at least k of each character, or return -1 if it is not possible to take k of each character.
  
// Example 1:
// Input: s = "aabaaaacaabc", k = 2
// Output: 8
// Explanation: 
// Take three characters from the left of s. You now have two 'a' characters, and one 'b' character.
// Take five characters from the right of s. You now have four 'a' characters, two 'b' characters, and two 'c' characters.
// A total of 3 + 5 = 8 minutes is needed.
// It can be proven that 8 is the minimum number of minutes needed.
  
// Example 2:
// Input: s = "a", k = 1
// Output: -1
// Explanation: It is not possible to take one 'b' or 'c' so return -1.


//Approach-1 : Brute Force - Recursion
//T.C : O(2^n)
//S.C : O(1) (But recursion stack space we are taking = O(n) in worst case i.e. depth of recursion will be equal to length of string)

class Solution {
public:

    int result = INT_MAX;

    void solve(string& s, int k, int i, int j, int minutes, vector<int> freq) {
        if(freq[0] >= k && freq[1] >= k && freq[2] >= k) {
            result = min(result, minutes);
            return;
        }
        if(i > j) //all characters visited
            return;


        //Option-1 : Delete from left
        vector<int> tempFreqLeft = freq;
        tempFreqLeft[s[i] - 'a'] += 1;
        solve(s, k, i+1, j, minutes+1, tempFreqLeft);

        //De;ete from right
        vector<int> tempFreqRight = freq;
        tempFreqRight[s[j] - 'a'] += 1;
        solve(s, k, i, j-1, minutes+1, tempFreqRight);

    }

    int takeCharacters(string s, int k) {
        vector<int> freq(3, 0);
        int i = 0;
        int j = s.length()-1;
        int minutes = 0;
        solve(s, k, i, j, minutes, freq);

        return result == INT_MAX ? -1 : result;
    }
};


//Approach-2 : Sliding Window
//T.C : O(n)
//S.C : O(1)

class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length();

        int count_a = 0; //delete
        int count_b = 0; //delete
        int count_c = 0; //delete
        for(char &ch : s) {
            if(ch == 'a')
                count_a++;
            else if(ch == 'b')
                count_b++;
            else
                count_c++;
        }

        if(count_a < k || count_b < k || count_c < k) {
            return -1; //not possible to delete k characters
        }

        int i = 0;
        int j = 0; 
        int notDeletedWindowSize = 0;

        while(j < n) {
            if(s[j] == 'a') {
                count_a--;
            } else if(s[j] == 'b') {
                count_b--;
            } else if(s[j] == 'c') {
                count_c--;
            }

            //if deletion count of any character becomes less than k, then shrink the window and bring them back
            while(i <= j && (count_a < k || count_b < k || count_c < k)) {
                //ith pointer move to left
                if(s[i] == 'a') {
                    count_a++;
                } else if(s[i] == 'b') {
                    count_b++;
                } else {
                    count_c++;
                }
                i++;
            }

            notDeletedWindowSize = max(notDeletedWindowSize, j-i+1);
            j++;
        }

        return n - notDeletedWindowSize; //minutes

    }
};
