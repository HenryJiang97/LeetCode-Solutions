class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        vector<int> res;
        unordered_map<int, int> x, y, d1, d2;
        unordered_map<int, unordered_set<int>> ls;
        
        for (auto& l : lamps) {
            int i = l[0], j = l[1];
            if (ls.count(i) == 0 || ls[i].count(j) == 0) {    // If this lamp is not counted before
                x[i]++;    y[j]++;    d1[i + j]++;    d2[i - j]++;
                ls[i].insert(j);
            }
        }
        
        for (auto& query : queries) {
            int i = query[0], j = query[1];
            if (x[i] || y[j] || d1[i + j] || d2[i - j]) {    // Lamp exists
                res.push_back(1);
                // Remove from maps
                for (auto li = i - 1; li <= i + 1; ++li)
                    for (auto lj = j - 1; lj <= j + 1; ++lj){
                      if (ls[li].erase(lj)) {
                        --x[li], --y[lj], --d1[li + lj], --d2[li - lj];
                      }
                    }
            }
            else
                res.push_back(0);
        }
        
        return res;
    }
};