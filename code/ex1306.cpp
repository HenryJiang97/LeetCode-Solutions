class Solution {
    bool res = 0;
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n);
        dfs(arr, visited, start);
        return res;
    }
    
private:
    void dfs(vector<int>& arr, vector<bool>& visited, int cur) {
        if (arr[cur] == 0) {
            res = 1;
            return;
        }
        
        int nxt = cur - arr[cur];
        if (nxt >= 0 && !visited[nxt]) {
            visited[nxt] = 1;
            dfs(arr, visited, nxt);
            if (res)    return;
        }
        
        nxt = cur + arr[cur];
        if (nxt < arr.size() && !visited[nxt]) {
            visited[nxt] = 1;
            dfs(arr, visited, nxt);
            if (res)    return;
        }
    }
};