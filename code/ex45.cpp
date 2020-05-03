class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> end(n);
        for (int i = 0; i < n; i++)
            end[i] = min(n - 1, i + nums[i]);
        
        int i = 0, cnt = 0;
        while (i < n - 1) {
            cnt++;
            int MAX = i + 1;
            for (int j = i + 1; j <= end[i] && j < n; j++) {
                if (end[j] >= end[MAX])
                    MAX = j;
            }
            i = MAX;
        }
        
        return cnt;
    }
};