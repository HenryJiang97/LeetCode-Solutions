class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size(), n = nums[0].size();
        if (r * c != m * n)    return nums;
        
        int i = 0, j = 0;
        vector<vector<int>> res;
        vector<int> temp;
        while (i < m) {
            temp.push_back(nums[i][j]);
            if (temp.size() >= c) {
                res.push_back(temp);
                temp.clear();
            }
            
            j++;
            if (j >= n) {
                i++;
                j = 0;
            }
        }
        
        return res;
    }
};