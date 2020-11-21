class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& fc) {
        int n = fc.size();
        
        // Get person bitset for each company
        unordered_map<string, bitset<100>> c2p;
        for (int i = 0; i < fc.size(); i++) {
            for (string c : fc[i]) {
                c2p[c][i] = 1;
            }
        }
        
        // Get non-subsets
        vector<int> res;
        for (int i = 0; i < fc.size(); i++) {
            bitset<100> bs;
            bs.set();
            for (int j = 0; j < fc[i].size(); j++) {
                bs &= c2p[fc[i][j]];
            }
            if (bs.count() == 1)    res.push_back(i);
        }
        
        return res;
    }
};