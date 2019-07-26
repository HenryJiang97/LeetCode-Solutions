class Solution {
    int row = 0, col = 0;
    unordered_map<int, unordered_set<int>> map;
public:
    Solution(int n_rows, int n_cols) {
        row = n_rows;    col = n_cols;
    }
    
    vector<int> flip() {
        // Find a valid row
        int rand_row = rand() % row;
        while (map[rand_row].size() == col)
            rand_row = rand() % row;
        
        // Find a valid column
        int rand_col = rand() % col;
        while (map[rand_row].find(rand_col) != map[rand_row].end())
            rand_col = rand() % col;
        
        map[rand_row].insert(rand_col);
        return {rand_row, rand_col};
    }
    
    void reset() {
        map.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */