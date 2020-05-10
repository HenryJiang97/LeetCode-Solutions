class Solution {
public:
    double myPow(double x, int n) {
        double power = fastPow(x, n);
        return n > 0 ? power : 1.0 / power;
    }
    
private:
    double fastPow(double x, long n) {
        if (n == 0)    return 1.0;
        
        double halfPow = fastPow(x, n / 2);
        if (n % 2 == 0)
            return halfPow * halfPow;
        else
            return halfPow * halfPow * x;
    }
};