// You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.
// The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.
// Return the maximum score of a pair of sightseeing spots.
  
// Example 1:
// Input: values = [8,1,5,2,6]
// Output: 11
// Explanation: i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
  
// Example 2:
// Input: values = [1,2]
// Output: 2


//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        int result = 0;

        for(int j = 1; j < n; j++) {
            int max_val = 0;
            for(int i = j-1; i >= 0; i--) {
                max_val = max(max_val, values[i]+i);
            }

            result = max(result, max_val + values[j]-j);
        }

        return result;
    }
};


//Approach-2 (Using extra space)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        vector<int> vec(n, 0);
        //vec[i] = stores the maximum value of (values[i]+i) till index i in values wala array
        vec[0] = values[0] + 0;

        for(int i = 1; i < n; i++) {
            vec[i] = max(values[i]+i, vec[i-1]);
        }

        int result = 0;

        for(int j = 1; j < n; j++) {
            int x = values[j]-j;
            int y = vec[j-1]; //max value of (values[i]+i) in left hand side

            result = max(result, x+y);
        }

        return result;
    }
};


//Approach-3 (Using O(1) space)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        int result = 0;

        int max_till_now = values[0]+0; //this stores the max value of (values[i]+i) till now

        for(int j = 1; j < n; j++) {
            int x = values[j]-j;
            int y = max_till_now;

            result = max(result, x+y);

            max_till_now = max(max_till_now, values[j]+j);
        }

        return result;
    }
};
