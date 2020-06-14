class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> greater;
        stack<int> stk;    // Monotonously decreasing
        for (int i = nums2.size() - 1; i >= 0; --i) {
            while (!stk.empty() && nums2[i] >= stk.top())
                stk.pop();
            greater[nums2[i]] = stk.empty() ? -1 : stk.top();
            stk.push(nums2[i]);
        }
        
        // Get results
        vector<int> res;
        for (int num : nums1)
            res.push_back(greater[num]);
        
        return res;
    }
};