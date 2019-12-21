typedef pair<int, int> ii;

class Solution {
public:
    string rearrangeString(string s, int k) {
        int n = s.length();
        int cnt[26] = {0};
        for (char c : s)    cnt[c - 'a']++;
        
        // Create a heap for existing chars
        priority_queue<ii> pq;
        for (int i = 0; i < 26; ++i)
            if (cnt[i] != 0)
                pq.push({cnt[i], i});
        
        // Build string
        string res = "";
        vector<int> pos(26, -1);
        while (!isEmpty(pq)) {
            // Save invalid chars
            vector<ii> temp;
            while (!isEmpty(pq) && pos[pq.top().second] != -1 && res.length() - pos[pq.top().second] < k) {
                temp.push_back(pq.top());
                pq.pop();
            }
            if (isEmpty(pq))    break;
            
            // Add char to res
            int count = pq.top().first, c = pq.top().second;    pq.pop();
            res += (char)('a' + c);
            if (--count > 0)    pq.push({count, c});
            pos[c] = res.length() - 1;
            
            // Push pairs in temp back to pq
            for (ii t : temp)
                pq.push(t);
        }
        
        return res.length() == s.length() ? res : "";
    }
    
    bool isEmpty(priority_queue<ii>& pq) {
        return pq.empty() || pq.top().first == 0;
    }
};