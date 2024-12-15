// There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array classes, where classes[i] = [passi, totali]. You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.
// You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed to pass the exam of any class they are assigned to. You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio across all the classes.
// The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.
// Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the actual answer will be accepted.

// Example 1:
// Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
// Output: 0.78333
// Explanation: You can assign the two extra students to the first class. The average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.
  
// Example 2:
// Input: classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
// Output: 0.53485

//Approach-1 : (Chossing class with max delta/improvement everytime) - Will give TLE/MLE
//T.C : O(extraStudents * n)
//S.C : O(n)
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        vector<double> PR(n);
        for(int i = 0; i < n; i++) {
            double ratio = (double)classes[i][0]/classes[i][1];
            PR[i] = ratio;
        }

        while(extraStudents--) { //O(n)
            //student 0

            vector<double> updatedPR(n);
            for(int i = 0; i < n; i++) {
                double newRatio = (double)(classes[i][0]+1)/(classes[i][1]+1);
                updatedPR[i] = newRatio;
            }

            int bestClassIdx = 0;
            double bestDelta = 0;

            for(int i = 0; i < n; i++) { //O(n)
                double delta = updatedPR[i] - PR[i];
                if(delta > bestDelta) {
                    bestDelta = delta;
                    bestClassIdx = i;
                }
            }

            PR[bestClassIdx] = updatedPR[bestClassIdx];
            classes[bestClassIdx][0]++;
            classes[bestClassIdx][1]++;
        }

        double result = 0.0; //AR
        for(int i = 0; i < n; i++) {
            result += PR[i];
        }

        return result/n;
    }
};



//Approach-2 : (Chossing class with max delta/improvement everytime - Improving with max heap)
//T.C : O(extraStudents * log(n))
//S.C : O(n)
class Solution {
public:
    #define P pair<double, int>
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        priority_queue<P> pq; //max-heap  -  //{max-delta, idx}

        for(int i = 0; i < n; i++) {
            double current_PR = (double)classes[i][0]/classes[i][1];
            double new_PR = (double)(classes[i][0]+1)/(classes[i][1]+1);
            double delta = new_PR - current_PR;
            pq.push({delta, i});
        }
        
        //O(extraStudents * log(n))
        while(extraStudents--) { //O(k)
            auto curr = pq.top(); //log(n)
            pq.pop();

            double delta = curr.first;
            int idx = curr.second;

            classes[idx][0]++; //incremeent total passing students in the class
            classes[idx][1]++; //increment total students oin the class

            double current_PR = (double)classes[idx][0]/classes[idx][1];
            double new_PR = (double)(classes[idx][0]+1)/(classes[idx][1]+1);
            delta = new_PR - current_PR;
            pq.push({delta, idx}); //log(n)
        }

        double result = 0.0;
        for(int i = 0; i < n; i++) {
            result += (double)classes[i][0]/classes[i][1];
        }

        return result/n;
    }
};
