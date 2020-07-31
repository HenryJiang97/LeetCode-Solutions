class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> cnt;
        for (int bar : barcodes)    cnt[bar]++;
        
        priority_queue<pair<int, int>> pq;
        for (auto& [k, v] : cnt)
            pq.push({v, k});
        
        vector<int> res;
        while (!pq.empty()) {
            pair<int, int> top = pq.top();    pq.pop();
            if (res.size() > 0 && res.back() == top.second) {
                pair<int, int> nxt = pq.top();    pq.pop();
                res.push_back(nxt.second);
                if (--nxt.first > 0)    pq.push(nxt);
                pq.push(top);
            } else {
                res.push_back(top.second);
                if (--top.first > 0)    pq.push(top);
            }
        }
        
        return res;
    }
};