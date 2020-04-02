typedef long long ll;

class Solution {
public:
    int myAtoi(string str) {
        int n = str.length();
        
        ll num = 0;
        int sign = 1;
        
        // Skip all spaces at the front
        int i = 0;
        while (i < n && str[i] == ' ')    i++;
        if (i >= n)    return 0;
        
        // Get the sign if possible
        if (i < n && (str[i] == '-' || str[i] == '+')) {
            sign = str[i] == '-' ? -1 : 1;
            i++;
        }
        if (i >= n)    return 0;
        
        // Get the numbers after spaces and sign
        while (i < n) {
            if (!(str[i] >= '0' && str[i] <= '9'))    break;
            num = num * 10 + (int)(str[i] - '0');
            if (num * sign > INT_MAX)    return INT_MAX;
            if (num * sign < INT_MIN)    return INT_MIN;
            i++;
        }
        
        return (int)(num * sign);
    }
};