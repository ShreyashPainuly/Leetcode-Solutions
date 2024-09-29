// Example 1:
// Input: timePoints = ["23:59","00:00"]
// Output: 1

// Example 2:
// Input: timePoints = ["00:00","23:59","00:00"]
// Output: 0

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes(timePoints.size());
        //covert given times into minutes
        for(int i = 0; i < timePoints.size(); i++) {
            //coverting hour string into integer 
            int hr = stoi(timePoints[i].substr(0, 2));
            //coverting minutes string into integer 
            // m here -> minutes
            int m = stoi(timePoints[i].substr(3));
            minutes[i] = hr * 60 + m;
        }

        //sort the times in ascending order
        sort(minutes.begin(), minutes.end());

        //finding minimum time difference across adjacent elements
        int ans = INT_MAX;
        for(int i = 0; i < minutes.size() - 1; i++) {
            ans = min(ans, minutes[i+1] - minutes[i]);
        }

        //find the circular difference between last and first element
        int CircularDiff = (24 * 60 - minutes.back() + minutes.front());

        //compare circular diffference and existing answer
        ans = min(ans, CircularDiff);

        return ans;
    }
};
