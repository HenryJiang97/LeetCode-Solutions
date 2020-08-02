class Solution {
public:
    string addStrings(string num1, string num2) {
        int p1 = num1.size() - 1, p2 = num2.size() - 1, carry = 0;
        string res = "";
        while (p1 >= 0 || p2 >= 0 || carry > 0) {
            int d1 = (p1 >= 0 ? num1[p1] - '0' : 0), d2 = (p2 >= 0 ? num2[p2] - '0' : 0);
            int sum = d1 + d2 + carry;
            res = (char)('0' + sum % 10) + res;
            carry = sum / 10;
            p1--;    p2--;
        }
        return res;
    }
};