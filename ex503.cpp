// Stack

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> newNums(2 * n);
        for (int i = 0; i < n; i++)    newNums[i] = nums[i];
        for (int i = 0; i < n; i++)    newNums[i + n] = nums[i];
        
        vector<int> temp(n * 2, INT_MIN);
        stack<pair<int, int>> stack;
        for (int i = 0; i < 2 * n; i++) {
            while (!stack.empty() && newNums[i] > stack.top().first) {
                temp[stack.top().second] = newNums[i];
                stack.pop();
            }   
            stack.push(make_pair(newNums[i], i));
        }
        
        // Get result
        vector<int> res(n);
        for (int i = 0; i < n; i++)
            res[i] = temp[i] == INT_MIN ? -1 : temp[i];
        
        return res;
    }
};