class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res = "";
        
        priority_queue<pair<int, char>> pq;
        if (a > 0)    pq.push({a, 'a'});
        if (b > 0)    pq.push({b, 'b'});
        if (c > 0)    pq.push({c, 'c'});
        
        while (!pq.empty()) {
            pair<int, char> top = pq.top();    pq.pop();
            if (res.size() >= 2 && res.back() == top.second && res[res.size() - 2] == top.second) {
                // Cannot use top.second any more
                if (pq.empty())    return res;
                pair<int, char> nxt = pq.top();    pq.pop();
                res.push_back(nxt.second);
                if (nxt.first - 1 > 0)    pq.push({nxt.first - 1, nxt.second});
                pq.push({top.first, top.second});
            } else {
                res.push_back(top.second);
                if (top.first - 1 > 0)    pq.push({top.first - 1, top.second});
            }
        }
        
        return res;
    }
};