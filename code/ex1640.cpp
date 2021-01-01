class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, int> map;
        for (int i = 0; i < pieces.size(); i++) {
            map[pieces[i][0]] = i;
        }
        return backtracking(arr, pieces, map, 0);
    }
    
private:
    bool backtracking(vector<int>& arr, vector<vector<int>>& pieces, unordered_map<int, int>& map, int cur) {
        if (cur >= arr.size())    return 1;
        if (map.count(arr[cur]) == 0)    return 0;
        for (int val : pieces[map[arr[cur]]]) {
            if (arr[cur++] != val)    return 0;
        }
        return backtracking(arr, pieces, map, cur);
    }
};