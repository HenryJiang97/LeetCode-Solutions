typedef long long ll;

class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        ll mod = 1e9 + 7;
        ll GCD = gcd(A, B), LCM = (ll)A / GCD * B;
        
        ll lo = 2, hi = (ll)1e18;
        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;
            
            ll n = mid / A + mid / B - mid / LCM;    // Number of magical numbers <= mid
            if (n < N) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        
        return (int)(hi % mod);
    }
    
private:
    int gcd(int a, int b) {
        int t;
        while (b > 0) {
            t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
};