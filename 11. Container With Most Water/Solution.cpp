// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
// Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.
// Notice that you may not slant the container.
 
// Example 1:
// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

// Example 2:
// Input: height = [1,1]
// Output: 1

//Why does my solution given below works ?
/*
Idea / Proof (Gathered from Discussion Section of Leetcode from some intelligent programmers) : 
    The widest container (using first and last line) is a good candidate, because of its width.
    Its water level is the height of the smaller one of first and last line. All other containers
    are less wide and thus would need a higher water level in order to hold more water. The smaller
    one of first and last line doesn't support a higher water level and can thus be safely removed from further consideration.
*/

//Approach : Using Two Pointer (Greedy)
//T.C : O(n)
//S.C : O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int i = 0;
        int j = n-1;
        int maxWater = 0;

        while(i < j) {
            int h = min(height[i], height[j]);
            int w = j - i;

            int area = h * w;

            maxWater = max(maxWater, area);

            if(height[i] > height[j]) {
                j--;
            }
            else {
                i++;
            }
        }
        return maxWater;
    }
};
