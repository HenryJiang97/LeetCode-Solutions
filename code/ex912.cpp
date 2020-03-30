// Quick sort

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
    
private:
    void quickSort(vector<int>& nums, int lo, int hi) {
        if (lo >= hi)    return;
        int p = partition(nums, lo, hi);
        quickSort(nums, lo, p - 1);
        quickSort(nums, p + 1, hi);
    }
    
    int partition(vector<int>& nums, int lo, int hi) {
        int pivot = nums[lo];
        int p1 = lo + 1, p2 = hi;
        while (1) {
            while (p1 <= p2 && nums[p1] <= pivot)    p1++;
            while (p1 <= p2 && nums[p2] >= pivot)    p2--;
            if (p1 >= p2)    break;
            swap(nums, p1, p2);
        }
        int split = p2;
        swap(nums, lo, split);
        return split;
    }
    
    void swap(vector<int>& nums, int p1, int p2) {
        int temp = nums[p1];
        nums[p1] = nums[p2];
        nums[p2] = temp;
    }
};