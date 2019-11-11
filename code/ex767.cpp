typedef pair<int, char> ic;

class Solution {
public:
    string reorganizeString(string S) {
        int n = S.length();
        vector<int> map(26, 0);
        for (char c : S)    map[c - 'a']++;
        
        priority_queue<ic> pq;
        for (int i = 0; i < 26; i++)
            if (map[i] > 0)
                pq.push({map[i], (char)(i + 'a')});
        
        string res = "";
        while (!pq.empty()) {
            vector<ic> temp;
            while (!pq.empty()) {
                ic top = pq.top();    pq.pop();
                int cnt = top.first;    char c = top.second;
                if (res.length() > 0 && c == res[res.length() - 1]) {
                    temp.push_back(top);
                    if (pq.empty())    return "";
                }
                else {
                    res += c;
                    if (--cnt > 0)    pq.push({cnt, c});
                    break;
                }
            }
            for (ic p : temp)
                pq.push(p);
        }
        
        return res;
    }
};