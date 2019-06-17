// Heap

struct cmp {
    bool operator() (vector<int>& a, vector<int>& b) {
        return a[0] > b[0];
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        if (m == 0 || n == 0)    return {};
        vector<vector<int>> res;
        
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        pq.push(vector<int>{nums1[0] + nums2[0], 0, 0});
        
        while (k > 0 && !pq.empty()) {
            vector<int> out = pq.top();
            pq.pop();
            int i = out[1], j = out[2];
            res.push_back({nums1[i], nums2[j]});
            k--;
            
            if (j + 1 < n)    pq.push({nums1[i] + nums2[j + 1], i, j + 1});
            if (j == 0 && i + 1 < m)    pq.push({nums1[i + 1] + nums2[j], i + 1, j});
        }
        
        return res;
    }
};