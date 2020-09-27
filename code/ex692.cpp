struct cmp {
    bool operator()(pair<int, string>& a, pair<int, string>& b) {
        return a.first != b.first ? a.first > b.first : a.second < b.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int K) {
        unordered_map<string, int> cnt;
        for (string word : words)    cnt[word]++;
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
        for (auto& [k, v] : cnt) {
            pq.push({v, k});
            if (pq.size() > K)    pq.pop();
        }
        vector<string> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};