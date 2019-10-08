// Union Find

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = 10000;
        
        // Define root map
        unordered_map<int, int> root;
        
        // Build map for x coordinate and y coordinate
        unordered_map<int, vector<int>> mapX, mapY;
        for (auto& stone : stones) {
            int i = stone[0], j = stone[1];
            root[i * n + j] = i * n + j;
            mapX[i].push_back(i * n + j);
            mapY[j].push_back(i * n + j);
        }
        
        // Union stones on the same x coordinate
        for (auto entry : mapX) {
            vector<int>& group = entry.second;
            int point0 = group[0];
            for (int i = 1; i < group.size(); i++) {
                uni(root, point0, group[i]);
            }
        }
        
        // Union stones on the same y coordinate
        for (auto entry : mapY) {
            vector<int>& group = entry.second;
            int point0 = group[0];
            for (int i = 1; i < group.size(); i++) {
                uni(root, point0, group[i]);
            }
        }
        
        unordered_set<int> set;
        for (auto& stone : stones) {
            int node = stone[0] * n + stone[1];
            set.insert(find(root, node));
        }
        
        return stones.size() - set.size();
    }
    
private:
    int find(unordered_map<int, int>& root, int p) {
        if (root[p] != p)
            root[p] = find(root, root[p]);
        return root[p];
    }
    
    void uni(unordered_map<int, int>& root, int a, int b) {
        int ra = find(root, a), rb = find(root, b);
        if (ra <= rb)
            root[rb] = ra;
        else
            root[ra] = rb;
    }
};