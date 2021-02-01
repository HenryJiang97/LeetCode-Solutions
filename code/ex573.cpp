class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int dis = 0;
        
        // Get the total distance between tree and every nuts
        // Get the minimal distance to get every nuts
        int minDiff = INT_MAX;
        for (auto& nut : nuts) {
            dis += getDis(nut, tree);
            minDiff = min(minDiff, getDis(squirrel, nut) - getDis(nut, tree));
        }
        
        return dis * 2 + minDiff;
    }
    
private:
    int getDis(vector<int>& p1, vector<int>& p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
};