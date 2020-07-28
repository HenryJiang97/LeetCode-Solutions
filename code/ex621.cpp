// Priority queue

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> dict(26);
        for (char task : tasks)    dict[task - 'A']++;
        
        priority_queue<int> pq;
        for (int a : dict)    if (a != 0)    pq.push(a);
        
        int intervals = 0;
        while (!pq.empty()) {
            vector<int> temp;
            
            for (int i = 0; i <= n; i++) {
                if (!pq.empty()) {
                    if (pq.top() - 1 > 0)    temp.push_back(pq.top() - 1);
                    pq.pop();
                }
                intervals++;
                
                // Break when the last round is completed
                if (pq.empty() && temp.size() == 0)    return intervals;
            }
            
            // Add nums in temp back to queue
            for (int t : temp)    pq.push(t);
        }
        
        return intervals;
    }
};