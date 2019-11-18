class Solution {
    unordered_map<int, int> mirror;
    int n;
public:
    Solution(int N, vector<int>& blacklist) {
        unordered_set<int> frontbl(blacklist.begin(), blacklist.end());
        int frontlen = N - blacklist.size();
        n = frontlen;
        // Delete black holes outside the front range
        for (int i = frontlen; i < N; i++) {
            if (frontbl.find(i) != frontbl.end())    frontbl.erase(i);
        }
        
        // Mirror white elements outside front range to black holes with in front range
        unordered_set<int> bl(blacklist.begin(), blacklist.end());
        auto it = frontbl.begin();
        for (int i = frontlen; i < N; i++) {
            if (bl.find(i) != bl.end())    continue;    // Skip black holes
            mirror[*it] = i;
            it++;
        }
    }
    
    int pick() {
        int random = rand() % n;
        return mirror.find(random) != mirror.end() ? mirror[random] : random;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */