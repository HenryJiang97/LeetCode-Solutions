// Maintain a subset array of size k, add the elements from nums array recursively to the subset array

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Get the target sum of each subset
        int sum = 0;
        for (auto num : nums)    sum += num;
        if (sum % k != 0)    return false;
        sum /= k;

        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> subset(k, 0);
        return helper(nums, k, sum, subset, 0);
    }
    
private:
    bool helper(vector<int>& nums, int k, int target, vector<int>& subset, int start) {
        if (start >= nums.size())    return true;
        
        for (int j = 0; j < k; j++) {
            if (j > 0 && subset[j - 1] == 0)    return false;
            
            if (nums[start] + subset[j] > target)    continue;
            subset[j] += nums[start];
            if (helper(nums, k, target, subset, start + 1))    return true;
            subset[j] -= nums[start];
        }
        
        return false;
    }
};