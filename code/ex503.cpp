// Monotone stack

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; i++)    nums.push_back(nums[i]);
        
        vector<int> temp(2 * n, -1);
        stack<int> stk;    stk.push(0);
        
        for (int i = 1; i < 2 * n; i++) {
            while (!stk.empty() && nums[stk.top()] < nums[i]) {
                temp[stk.top()] = nums[i];
                stk.pop();
            }
            stk.push(i);
        }
        
        // Copy the first n elements to the result
        vector<int> res(temp.begin(), temp.begin() + n);
        
        return res;
    }
};