class Solution {
public:
    string decodeString(string s) {
        queue<char> que;
        for (char c : s)
            que.push(c);
        return decode(que);
    }
    
private:
    string decode(queue<char>& que) {
        string s = "";
        int num = 0;
        while (!que.empty()) {
            char c = que.front();    que.pop();
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                s += buildString(num, decode(que));
                num = 0;
            } else if (c == ']') {
                return s;
            } else {
                s += c;
            }
        }
        return s;
    }
    
    string buildString(int n, string s) {
        string res = "";
        for (int i = 0; i < n; i++)
            res += s;
        return res;
    }
};