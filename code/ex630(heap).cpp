// Priority Queue

struct cmp {
    bool operator() (vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
};

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), cmp());
        priority_queue<int> pq;
        
        int cur_time = 0;    // Current time till now
        for (auto& course : courses) {
            if (cur_time + course[0] <= course[1]) {
                cur_time += course[0];    pq.push(course[0]);
            } else if (!pq.empty() && pq.top() > course[0]) {
                // Delete the longest course in the queue
                cur_time -= pq.top();
                pq.pop();
                // Add current course to the queue
                cur_time += course[0];    pq.push(course[0]);
            }
        }
        
        return pq.size();
    }
};