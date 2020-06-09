class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0;
        for (int i = 0; i < k; i++)    sum += nums[i];
        double MAX = (double)sum / k;
        
        for (int i = k; i < n; i++) {
            sum += nums[i] - nums[i - k];
            MAX = max(MAX, (double)sum / k);
        }
        
        return MAX;
    }
};