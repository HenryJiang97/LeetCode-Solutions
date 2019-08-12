// BFS

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> color(n);
        
        for (int i = 0; i < n; i++) {
            if (color[i] != 0)    continue;
            
            // Init queue
            queue<int> que;
            color[i] = 1;
            que.push(i);
            
            // BFS through this tree
            int sign = -1;
            while (!que.empty()) {
                int size = que.size();

                for (int i = 0; i < size; i++) {    // Loop through current layer in the graph
                    int out = que.front();    que.pop();
                    vector<int> children = graph[out];

                    for (auto child : children) {    // Loop through children nodes of current out node
                        if (color[child] == -sign)    return false;
                        if (color[child] == sign)    continue;

                        color[child] = sign;
                        que.push(child);
                    }
                }

                sign = -sign;
            }
            
            
        }

        return true;
    }
};