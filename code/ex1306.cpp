class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        
        queue<int> que;
        que.push(start);
        vector<bool> visited(n);
        visited[start] = 1;
        
        while (!que.empty()) {
            int out = que.front();    que.pop();
            if (arr[out] == 0)    return 1;
            if (out + arr[out] < n && !visited[out + arr[out]]) {
                que.push(out + arr[out]);
                visited[out + arr[out]] = 1;
            }
            if (out - arr[out] >= 0 && !visited[out - arr[out]]) {
                que.push(out - arr[out]);
                visited[out - arr[out]] = 1;
            }
        }
        
        return 0;
    }
};