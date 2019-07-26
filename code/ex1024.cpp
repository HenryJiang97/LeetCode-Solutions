// Greedy

struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        if (a[1] != b[1])    return a[1] < b[1];
        else    return a[0] > b[0];
    }
};

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        int n = clips.size();
        sort(clips.begin(), clips.end(), cmp());
        if (clips[n - 1][1] < T)    return -1;
        
        // Find the first clip
        int last = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (clips[i][0] == 0) {
                last = i;
                break;
            }
        }
        if (last == -1)    return -1;
        
        //
        int cnt = 1;
        while (true) {
            if (clips[last][1] >= T)    return cnt;
            
            int i;
            for (i = n - 1; i > last; i--) {
                if (clips[i][0] <= clips[last][1]) {
                    cnt++;    break;
                }
            }
            
            if (i <= last)    return -1;
            last = i;
        }

        return -1;
    }
};