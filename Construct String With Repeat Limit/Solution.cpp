// You are given a string s and an integer repeatLimit. Construct a new string repeatLimitedString using the characters of s such that no letter appears more than repeatLimit times in a row. You do not have to use all characters from s.
// Return the lexicographically largest repeatLimitedString possible.
// A string a is lexicographically larger than a string b if in the first position where a and b differ, string a has a letter that appears later in the alphabet than the corresponding letter in b. If the first min(a.length, b.length) characters do not differ, then the longer string is the lexicographically larger one.
  
// Example 1:
// Input: s = "cczazcc", repeatLimit = 3
// Output: "zzcccac"
// Explanation: We use all of the characters from s to construct the repeatLimitedString "zzcccac".
// The letter 'a' appears at most 1 time in a row.
// The letter 'c' appears at most 3 times in a row.
// The letter 'z' appears at most 2 times in a row.
// Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
// The string is the lexicographically largest repeatLimitedString possible so we return "zzcccac".
// Note that the string "zzcccca" is lexicographically larger but the letter 'c' appears more than 3 times in a row, so it is not a valid repeatLimitedString.
  
// Example 2:
// Input: s = "aababab", repeatLimit = 2
// Output: "bbabaa"
// Explanation: We use only some of the characters from s to construct the repeatLimitedString "bbabaa". 
// The letter 'a' appears at most 2 times in a row.
// The letter 'b' appears at most 2 times in a row.
// Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
// The string is the lexicographically largest repeatLimitedString possible so we return "bbabaa".
// Note that the string "bbabaaa" is lexicographically larger but the letter 'a' appears more than 2 times in a row, so it is not a valid repeatLimitedString.


//Approach-1 (Using pointers and frequency table)
//T.C : O(n)
//S.C : O(26)
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> count(26, 0); //S.C : O(26)
        for(char &ch : s) { //T.C : O(n)
            count[ch-'a']++;
        }

        string result;

        int i = 25; //start form last letter so that we can find the largest character first
        while(i >= 0) { //O(26)
            if(count[i] == 0) {
                i--;
                continue;
            }

            char ch  = 'a' + i; //you will get the character
            int freq = min(count[i], repeatLimit);

            result.append(freq, ch);
            count[i] -= freq;

            if(count[i] > 0) {
                //find next largest character
                int j = i-1;
                while(j >= 0 && count[j] == 0) { //O(26)
                    j--;
                }

                if(j < 0) {
                    break;
                }

                result.push_back('a' + j);
                count[j]--;
            }
        }

        return result;
    }
};


//Approach-2 (Using max-heap + frequency table)
//T.C : O(n)
//S.C : O(26)
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> count(26, 0);
        for(char &ch : s) {
            count[ch-'a']++;
        }

        priority_queue<char> pq;
        for(int i = 0; i < 26; i++) {
            if(count[i] > 0) {
                char ch = 'a' + i;
                pq.push(ch);
            }
        }

        string result;
        while(!pq.empty()) {
            char ch = pq.top();
            pq.pop();

            int freq = min(count[ch-'a'], repeatLimit);
            result.append(freq, ch);

            count[ch-'a'] -= freq;

            if(count[ch-'a'] > 0 && !pq.empty()) {
                char nextChar = pq.top();
                pq.pop();

                result.push_back(nextChar);
                count[nextChar-'a']--;

                if(count[nextChar-'a'] > 0) {
                    pq.push(nextChar);
                }

                pq.push(ch);

            }
        }

        return result;
    }
};
