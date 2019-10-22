class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int K) {
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 == 0 || n2 == 0)    return {};
        
        vector<vector<int>> res;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({nums1[0] + nums2[0], 0, 0});
        int k = 0;
        
        while (!pq.empty()) {
            auto out = pq.top();    pq.pop();
            int p1 = out[1], p2 = out[2];
            res.push_back({nums1[p1], nums2[p2]});
            if (++k == K)    return res;
            
            // Push next larger pairs to the pq
            if (p1 + 1 < n1)    pq.push({nums1[p1 + 1] + nums2[p2], p1 + 1, p2});
            if (p1 == 0 && p2 + 1 < n2)    pq.push({nums1[p1] + nums2[p2 + 1], p1, p2 + 1});
        }
        
        return res;
    }
};