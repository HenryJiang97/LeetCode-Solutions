// BFS

class Solution {
public:
    int kSimilarity(string A, string B) {
        if (A == B)    return 0;
        int n = A.length();
        
        queue<string> que;
        que.push(A);
        int step = 0;
        unordered_set<string> visited;    visited.insert(A);
        
        while (!que.empty()) {
            for (int z = que.size(); z > 0; --z) {
                string out = que.front();    que.pop();
                
                // Find the position while the letter mismatch
                int i = 0;
                while (out[i] == B[i])    i++;
                
                // Find the right letter behind it for swap
                for (int j = i + 1; j < n; j++) {
                    if (out[j] != B[i])    continue;
                    
                    // Get the new string after swap
                    string new_str = out;
                    new_str[i] = out[j];    new_str[j] = out[i];
                    
                    if (new_str == B)    return step + 1;
                    else {
                        if (visited.find(new_str) == visited.end())    que.push(new_str);
                        visited.insert(new_str);
                    }
                }
            }
            step++;
        }
        
        return -1;
    }
};