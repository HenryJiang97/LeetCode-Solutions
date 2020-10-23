class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end());
        
        int n = clips.size(), cnt = 0, end = 0, p = 0;
        while (p < n && end < T) {
            int newEnd = end;
            while (p < n && clips[p][0] <= end)    newEnd = max(newEnd, clips[p++][1]);
            if (newEnd == end)    break;
            cnt++;
            end = newEnd;
        }
        
        return end >= T ? cnt : -1;
    }
};