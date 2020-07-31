class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> cnt;
        for (char c : S)    cnt[c]++;
        
        priority_queue<pair<int, char>> pq;
        for (auto& [k, v] : cnt)
            pq.push({v, k});
        
        string res = "";
        while (!pq.empty()) {
            pair<int, char> top = pq.top();    pq.pop();
            if (res.size() > 0 && res.back() == top.second) {
                if (pq.empty())    return "";
                pair<int, char> nxt = pq.top();    pq.pop();
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