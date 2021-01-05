class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        int n1 = slots1.size(), n2 = slots2.size();
        int p1 = 0, p2 = 0;
        while (p1 < n1 && p2 < n2) {
            while (p1 < n1 && slots2[p2][0] > slots1[p1][1])    p1++;
            while (p2 < n2 && slots1[p1][0] > slots2[p2][1])    p2++;
            if (p1 >= n1 || p2 >= n2)    break;
            int start = max(slots1[p1][0], slots2[p2][0]);
            int end = min(slots1[p1][1], slots2[p2][1]);
            if (end - start >= duration)    return {start, start + duration};
            if (slots1[p1][1] < slots2[p2][1])    p1++;
            else    p2++;
        }
        return {};
    }
};