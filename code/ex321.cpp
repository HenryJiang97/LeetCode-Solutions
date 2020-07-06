class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        
        vector<int> MAX;
        for (int i = 0; i <= k; i++) {
            int j = k - i;
            if (i > n1 || j > n2)    continue;
            vector<int> max1 = getMaxArray(nums1, i);
            vector<int> max2 = getMaxArray(nums2, j);
            vector<int> merged = merge(max1, max2);
            MAX = max(MAX, merged);
        }
        
        return MAX;
    }
    
private:
    // Get max array with length
    vector<int> getMaxArray(vector<int>& nums, int len) {    // O(n)
        int del = nums.size() - len;
        vector<int> res;
        for (int num : nums) {
            while (!res.empty() && res.back() < num && del > 0) {
                res.pop_back();
                del--;
            }
            res.push_back(num);
        }
        while (del > 0) {
            res.pop_back();
            del--;
        }
        return res;
    }
    
    // Merge two array
    vector<int> merge(vector<int>& arr1, vector<int>& arr2) {    // O(n)
        int n1 = arr1.size(), n2 = arr2.size();
        vector<int> res;
        for (int i = 0; i < n1 + n2; i++) {
            if (arr1 > arr2) {
                res.push_back(arr1[0]);
                arr1.erase(arr1.begin());
            } else {
                res.push_back(arr2[0]);
                arr2.erase(arr2.begin());
            }
        }
        return res;
    }
};