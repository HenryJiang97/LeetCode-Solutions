class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        vector<int> res;
        unordered_map<int, int> x, y, d1, d2;    // Hash table for row, col, two diagonals
        unordered_map<int, unordered_set<int>> ls;    // Hash table for existing lamps
        
        // Lit the lamps
        for (auto& l : lamps) {
            int i = l[0], j = l[1];
            if (ls.count(i) == 0 || ls[i].count(j) == 0) {    // If this lamp is not counted before
                x[i]++;    y[j]++;    d1[i + j]++;    d2[i - j]++;
                ls[i].insert(j);
            }
        }
        
        // Process the query and dim the adjacent 8 lamps
        for (auto& query : queries) {
            int i = query[0], j = query[1];
            if (x[i] > 0 || y[j] > 0 || d1[i + j] > 0 || d2[i - j] > 0) {    // Lamp exists
                res.push_back(1);
                // Remove from maps
                for (auto li = i - 1; li <= i + 1; ++li) {
                    if (li < 0 || li >= N)    continue;
                    for (auto lj = j - 1; lj <= j + 1; ++lj){
                        if (lj < 0 || lj >= N)    continue;
                        if (ls.count(li) > 0 && ls[li].count(lj) > 0) {
                            x[li]--;    y[lj]--;    d1[li + lj]--;    d2[li - lj]--;
                            ls[li].erase(lj);
                        }
                    }
                }
            }
            else
                res.push_back(0);
        }
        
        return res;
    }
};