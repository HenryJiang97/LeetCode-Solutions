class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        
        int lo = 0, hi = n - 1;
        while (lo < hi && nums[lo] == 0)    lo++;
        while (lo < hi && nums[hi] == 2)    hi--;
        int i = lo;
        while (i <= hi) {
            if (nums[i] == 0)    {swap(nums[i], nums[lo++]);    i++;}
            else if (nums[i] == 2)    swap(nums[i], nums[hi--]);
            else    i++;
        }
    }
};