class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        if (N == 0)    return cells;
        N = (N - 1) % 14;
        for (int z = 0; z < N + 1; z++) {
            vector<int> temp{0};
            for (int j = 1; j < 7; j++)
                temp.push_back(cells[j - 1] == cells[j + 1] ? 1 : 0);
            temp.push_back(0);
            cells = temp;
        }
        return cells;
    }
};