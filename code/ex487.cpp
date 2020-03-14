class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        vector<int> notFlip(n + 1);
        vector<int> flip(n + 1);
        
        int MAX = 0;
        for (int i = 1; i <= n; i++) {
            if (nums[i - 1] == 0) {
                flip[i] = notFlip[i - 1] + 1;
            } else {
                notFlip[i] = notFlip[i - 1] + 1;
                flip[i] = flip[i - 1] + 1;
            }
            MAX = max(MAX, max(flip[i], notFlip[i]));
        }
        
        return MAX;
    }
};