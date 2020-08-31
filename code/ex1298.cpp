class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& containedKeys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size(), res = 0;
        
        unordered_set<int> keys;
        unordered_set<int> boxes;
        
        queue<int> que;
        vector<bool> visited(n);
        for (int ib : initialBoxes) {
            boxes.insert(ib);
            if (status[ib]) {
                que.push(ib);
                visited[ib] = 1;
            }
        }
        
        while (!que.empty()) {
            int out = que.front();    que.pop();
            res += candies[out];
            for (int key : containedKeys[out])    keys.insert(key);
            
            vector<int> toDelete;
            for (int box : containedBoxes[out])    boxes.insert(box);
            for (int box : boxes) {
                if (!visited[box] && (keys.count(box) > 0 || status[box])) {
                    que.push(box);
                    visited[box] = 1;
                }
                if (visited[box])    toDelete.push_back(box);
            }
            
            // Remove
            for (int d : toDelete)    boxes.erase(d);
        }
        
        return res;
    }
};