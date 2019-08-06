class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        // Get the prefix product of the array in both positive and negative sequence
        vector<int> positive(n), negative(n);
        positive[0] = nums[0];    negative[n - 1] = nums[n - 1];
        
        for (int i = 1; i < n; i++) {
            positive[i] = positive[i - 1] * nums[i];
            negative[n - i - 1] = negative[n - i] * nums[n - i - 1];
        }
        
        // Get the result
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int left = (i - 1 >= 0) ? positive[i - 1] : 1;
            int right = (i + 1 < n) ? negative[i + 1] : 1;
            res[i] = left * right;
        }
        
        return res;
    }
};