class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = watchedVideos.size();
        
        // BFS
        vector<bool> visited(n);
        visited[id] = 1;
        queue<int> que;
        que.push(id);
        
        int l = 0;
        unordered_map<string, int> cnt;
        while (!que.empty()) {
            int size = que.size();
            for (int z = size; z > 0; z--) {
                int out = que.front();    que.pop();
                if (l == level) {
                    for (string video : watchedVideos[out]) {
                        cnt[video]++;
                    }
                } else {
                    for (int fri : friends[out]) {
                        if (visited[fri])    continue;
                        visited[fri] = 1;
                        que.push(fri);
                    }
                }
            }
            l++;
        }
        
        // Get result
        vector<string> res;
        for (auto& [k, v] : cnt)    res.push_back(k);
        sort(res.begin(), res.end(), [&](string a, string b) -> bool {
            if (cnt[a] == cnt[b])    return a < b;
            else    return cnt[a] < cnt[b];
        });
        
        return res;
    }
};