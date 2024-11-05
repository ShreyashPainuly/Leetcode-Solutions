// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

// Example 1:
// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]
  
// Example 2:
// Input: temperatures = [30,40,50,60]
// Output: [1,1,1,0]
  
// Example 3:
// Input: temperatures = [30,60,90]
// Output: [1,1,0]

//Approach : Using Brute Force
//T.C : O(n^2)
//S.C : O(1)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
      
        vector<int> result(n, 0);
        for(int i = 0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                if(temperatures[j] > temperatures[i]) {
                    result[i] = j-i;
                    break;
                }
            }
        }
        return result;
    }
};

//Approach : Using Optimized Approach (Stack)
//T.C : O(n)
//S.C : O(n)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;

        vector<int> result(n);

        for(int i = n-1; i>=0; i--) {
            while(!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                st.pop();
            }

            if(st.empty()) {
                result[i] = 0;
            }
            else {
                result[i] = st.top() - i;
            }

            st.push(i);
        }
        return result;
    }
};
