class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)    return n;
        
        int increase = 1, decrease = 1;
        for (int i = 1; i < n; i++) {
            int newIncrease = increase;
            int newDecrease = decrease;
            if (nums[i] > nums[i - 1]) {    // Increase
                newIncrease = decrease + 1;
            } else if (nums[i] < nums[i - 1]) {    // Decrease
                newDecrease = increase + 1;
            }
            increase = newIncrease;
            decrease = newDecrease;
        }
        
        return max(increase, decrease);
    }
};