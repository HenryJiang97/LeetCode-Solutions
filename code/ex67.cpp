class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.length(), n2 = b.length();
        
        int p1 = n1 - 1, p2 = n2 - 1, carry = 0;
        string res;
        while (p1 >= 0 || p2 >= 0) {
            int d1 = p1 >= 0 ? a[p1--] - '0' : 0;
            int d2 = p2 >= 0 ? b[p2--] - '0' : 0;
            res = to_string((d1 + d2 + carry) % 2) + res;
            carry = (d1 + d2 + carry) / 2;
        }
        if (carry > 0)    res = '1' + res;
        
        return res;
    }
};