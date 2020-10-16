class Solution {
    string parent = "";
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, string> parent;
        for (vector<string>& region : regions) {
            for (int i = 1; i < region.size(); i++) {
                parent[region[i]] = region[0];
            }
        }
        
        vector<string> p1, p2;
        getParents(parent, region1, p1);
        getParents(parent, region2, p2);
        
        string res = "";
        for (int i1 = p1.size() - 1, i2 = p2.size() - 1; i1 >= 0 && i2 >= 0 && p1[i1] == p2[i2]; i1--, i2--) {
            res = p1[i1];
        }
        
        return res;
    }
    
private:
    void getParents(unordered_map<string, string>& parent, string cur, vector<string>& p) {
        p.push_back(cur);
        if (parent.count(cur) > 0)
            getParents(parent, parent[cur], p);
    }
};