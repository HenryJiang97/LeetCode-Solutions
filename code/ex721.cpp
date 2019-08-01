// Union find

class Solution {
    int n;
    
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        n = accounts.size();    
    
        unordered_map<string, string> root;
        unordered_map<string, string> parent;
        
        for (auto account : accounts) {
            string r = account[0];
            // Loop through emails for current account
            for (int i = 1; i < account.size(); i++) {
                root[account[i]] = r;
                parent[account[i]] = account[i];
            }
        }
        
        // Link email addresses belongs to the same user together
        for (auto account : accounts) {
            string p = unifind(account[1], parent);
            
            for (int i = 2; i < account.size(); i++) {
                parent[find(account[i], parent)] = p;
            }
        }
        
        // Collect all email addressed which belongs to one user account
        unordered_map<string, set<string>> map;
        for (auto account : accounts) {
            for (int i = 1; i < account.size(); ++i) {
                map[unifind(account[i], parent)].insert(account[i]);
            }
        }
        
        // Get the result
        vector<vector<string>> res;
        for (auto entry : map) {
            vector<string> r;
            r.push_back(root[entry.first]);
            for (auto it = entry.second.begin(); it != entry.second.end(); it++)
                r.push_back(*it);
            res.push_back(r);
        }
        
        return res;
    }
    
private:
    string unifind(string s, unordered_map<string, string>& parent) {
        if (parent[s] != s)    s = unifind(parent[s], parent);
        return s;
    }
};