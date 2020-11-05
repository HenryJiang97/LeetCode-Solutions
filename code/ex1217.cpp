class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd = 0, even = 0;
        for (int pos : position) {
            odd += pos % 2 == 1 ? 1 : 0;
            even += pos % 2 == 0 ? 1 : 0;
        }
        return min(odd, even);
    }
};