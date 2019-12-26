class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size())    return 0;
        int n = words1.size();
        unordered_map<string, string> parent;
        for (auto& pair : pairs) {
            string s1 = pair[0], s2 = pair[1];
            if (parent.find(s1) == parent.end())    parent[s1] = s1;
            if (parent.find(s2) == parent.end())    parent[s2] = s2;
            uni(parent, s1, s2);
        }
        
        for (int i = 0; i < n; i++) {
            string r1 = parent.find(words1[i]) == parent.end() ? words1[i] : find(parent, words1[i]);
            string r2 = parent.find(words2[i]) == parent.end() ? words2[i] : find(parent, words2[i]);
            if (r1 != r2)    return 0;
        }
        
        return 1;
    }

private:
    void uni(unordered_map<string, string>& parent, string s1, string s2) {
        string r1 = find(parent, s1), r2 = find(parent, s2);
        if (r1 < r2)
            parent[r2] = r1;
        else if (r1 > r2)
            parent[r1] = r2;
    }
    
    string find(unordered_map<string, string>& parent, string s) {
        cout<<s<<endl;
        if (parent[s] != s)
            parent[s] = find(parent, parent[s]);
        return parent[s];
    }
};