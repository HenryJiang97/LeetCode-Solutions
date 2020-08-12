class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.length(), n2 = num2.length();
        
        vector<string> mul;
        for (int i = n2 - 1; i >= 0; i--) {
            int carry = 0;
            string s = string(n2 - i - 1, '0');
            for (int j = n1 - 1; j >= 0; j--) {
                int sum = (num1[j] - '0') * (num2[i] - '0') + carry;
                carry = sum / 10;
                s = to_string(sum % 10) + s;
            }
            if (carry > 0)    s = to_string(carry) + s;
            mul.push_back(s);
        }
        
        string res = "";
        int carry = 0, n = mul.back().length();
        for (int i = 0; i < n; i++) {
            int digit = carry;
            for (string m : mul) {
                int len = m.length();
                if (len - i - 1 < 0)    continue;
                digit += (m[len - i - 1] - '0');
            }
            carry = digit / 10;
            res = to_string(digit % 10) + res;
        }
        if (carry > 0)    res = to_string(carry) + res;
        
        // Trim
        int p = 0;
        while (p < res.length() - 1 && res[p] == '0')    p++;
        
        return res.substr(p);
    }
};