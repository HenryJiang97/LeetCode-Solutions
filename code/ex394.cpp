class Solution {
    int n, c;
    
public:
    string decodeString(string s) {
        n = s.length();
        c = 0;
        return recurrsion(s);
    }
    
private:
    string recurrsion(string s) {
        string res = "";
        
        while (c < n) {            
            if (isdigit(s[c])) {
                int coe = 0;
                while (isdigit(s[c])) {
                    coe = coe * 10 + s[c] - '0';
                    c++;
                }
                if (s[c] == '[') {
                    c++;
                    string ret = recurrsion(s);
                    for (int i = 0; i < coe; i++)    res += ret;
                }
            } 
            else if (s[c] == ']') {
                c++;
                return res;
            }
            else {
                res += s[c++];
            }
        }
        
        return res;
    }
};