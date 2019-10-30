// Get the amount of numbers within a which can be diviible by a or b or c should be
// cnt = n / a + n / b + n / c - n / LCM(a, b) - n / LCM(a, c) - n / LCM(b, c) + n / LCM(a, b, c)
// * LCM(a, b) = a * b / GCD(a, b)

typedef long long ll;

class Solution {
public:
    int nthUglyNumber(ll n, ll a, ll b, ll c) {
        ll lo = 1, hi = 2 * (1e9);
        
        while (lo <= hi) {
            ll mid = lo + (hi - lo) / 2;
            if (getCount(mid, a, b, c) >= n)
                hi = mid - 1;
            else {
                if (getCount(mid + 1, a, b, c) == n)    return (int)(mid + 1);
                else    lo = mid + 1;
            }
        }
        
        return -1;
    }
    
private:
    ll getCount(ll n, ll a, ll b, ll c) {
        return n / a + n / b + n / c - n / LCM(a, b) - n / LCM(a, c) - n / LCM(b, c) + n / LCM(a, LCM(b, c));
    }
    
    ll LCM(ll a, ll b) {
        return a * b / GCD(a, b);
    }
    
    ll GCD(ll a, ll b) {
        ll temp = b;
        while (b != 0) {
            temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};