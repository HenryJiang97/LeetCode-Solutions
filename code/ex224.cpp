class Solution {
    private int i = 0;
    public int calculate(String s) {
        int n = s.length();
        int res = 0, temp = 0, sign = 1;
        while (i < n) {
            char c = s.charAt(i);

            if (c == ' ') {
                i++;
                continue;
            } else if (Character.isDigit(c)) {
                temp = temp * 10 + (c - '0');
                i++;
            } else {
                res += sign * temp;
                temp = 0;

                if (c == '+') {
                    sign = 1;
                    i++;
                } else if (c == '-') {
                    sign = -1;
                    i++;
                } else if (c == '(') {
                    i++;
                    int nxt = calculate(s);
                    if (nxt == Integer.MIN_VALUE)    return nxt;
                    else    res += sign * nxt;
                } else if (c == ')') {
                    i++;
                    return res;
                }
            }
        }
        if (temp != 0)    res += temp * sign;

        return res;
    }
}