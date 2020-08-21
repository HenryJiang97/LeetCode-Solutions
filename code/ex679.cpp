class Solution {
    vector<char> signs{'+', '-', '*', '/'};
public:
    bool judgePoint24(vector<int>& numbers) {
        vector<double> nums;
        for (int n : numbers)    nums.push_back((double)n);
        return backtracking(nums);
    }
    
private:
    bool backtracking(vector<double>& nums) {
        if (nums.empty())    return 0;
        if (nums.size() == 1)    return abs(nums.back() - 24) < 1e-4;
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i == j)    continue;
                double n1 = nums[i], n2 = nums[j];
                
                vector<double> newNums;
                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j)    newNums.push_back(nums[k]);
                }
                
                for (char sign : signs) {
                    if (sign == '+')    newNums.push_back(n1 + n2);
                    if (sign == '-')    newNums.push_back(n1 - n2);
                    if (sign == '*')    newNums.push_back(n1 * n2);
                    if (sign == '/')    newNums.push_back(n1 / n2);
                    if (backtracking(newNums))    return 1;
                    newNums.pop_back();
                }
            }
        }
        
        return 0;
    }
};