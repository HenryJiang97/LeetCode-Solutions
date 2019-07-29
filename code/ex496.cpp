// Monotone stack

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        for (int n : nums1)    map[n] = -1;
        
        stack<int> stk;
        for (int n : nums2) {
            while (!stk.empty() && stk.top() < n) {
                if (map.find(stk.top()) != map.end()) {
                    map[stk.top()] = n;
                }
                stk.pop();
            }
            stk.push(n);
        }
        
        vector<int> res(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            res[i] = map[nums1[i]];
        }
        
        return res;
    }
};