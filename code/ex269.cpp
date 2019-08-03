// Topological ordering

class Solution {
    int n = 0;
public:
    string alienOrder(vector<string>& words) {
        n = words.size();
        
        // Build graph
        unordered_map<char, set<char>> m;
        buildGraph(words, m);

        // Get indegree
        auto indegree = vector<int>(26, 0);
        for (auto entry: m) {
            for (auto c : entry.second) {
                indegree[c - 'a']++;
            }
        }
        
        // Topological ordering
        queue<char> que;
        for (auto entry : m) {    // Add every head node in the graph to the queue
            if (indegree[entry.first - 'a'] == 0) {
                que.push(entry.first);
            }
        }

        string res = "";
        while (!que.empty()) {
            char out = que.front();    que.pop();
            res += out;

            for (char child : m[out]) {
                // If the indegree of a node becomes zero, it can become a head node
                if (--indegree[child - 'a'] == 0)    que.push(child);
            }
        }
        
        return res.length() == m.size() ? res : "";
    }
    
private:
    void buildGraph(vector<string>& words, unordered_map<char, set<char>>& m) {
        for (int i = 0; i < n - 1; i++) {
            string s1 = words[i], s2 = words[i + 1];
            for (int p = 0; p < max(s1.length(), s2.length()); ++p) {
                if (p < s1.length() && p < s2.length() && s1[p] != s2[p]) {
                    m[s1[p]].insert(s2[p]);
                    break;
                }
            }
            // Add all char to the graph
            for (char c : s1)
                if (m.find(c) == m.end())    m[c] = set<char>();
        }
        for (char c : words[n - 1])
            if (m.find(c) == m.end())    m[c] = set<char>();
    }
};