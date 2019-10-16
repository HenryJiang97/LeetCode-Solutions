// Topological ordering
// Every time there must only be one node having no indegree, or there will be more than one ordering.
// Every node must exist in the sequence.
// O(max(nodes in seqs, nodes in org))

class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size();
        
        unordered_map<int, unordered_set<int>> m;
        unordered_set<int> set;
        for (auto& seq : seqs) {
            int l = seq.size();
            for (int i = 0; i < l - 1; i++) {
                m[seq[i]].insert(seq[i + 1]);
                set.insert(seq[i]);    set.insert(seq[i + 1]);
            }
            if (l == 1)    set.insert(seq[0]);
        }
        if (set.size() != n)    return false;
        
        
        // Get the indegree of each node
        vector<int> indegree(n + 1, 0);
        for (auto entry : m) {
            for (int next : entry.second) {
                indegree[next]++;
            }
        }
        
        // Add nodes having no indegree to the queue
        queue<int> que;
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                que.push(i);
                count++;
            }
        }
        if (count > 1)    return false;
        
        unordered_set<int> res;
        while (!que.empty()) {
            int out = que.front();    que.pop();
            res.insert(out);
            
            int cnt = 0;
            for (int next : m[out]) {
                if (--indegree[next] == 0) {
                    que.push(next);
                    cnt++;
                }
                if (cnt > 1)    return false;
            }
        }
        
        return res.size() == n;
    }
};