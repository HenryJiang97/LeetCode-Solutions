class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        
        int pold = 0, pnew = 0;
        for (pold = 0; pold < n; pold++)
            if (nums[pold] != val)
                nums[pnew++] = nums[pold];
        
        return pnew;
    }
};