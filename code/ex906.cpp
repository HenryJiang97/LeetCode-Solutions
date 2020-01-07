typedef long long ll;

class Solution {
public:
    int superpalindromesInRange(string L, string R) {
        ll lo = stoll(L), hi = stoll(R);
        int cnt = 0;
        for (int i = 1; i <= 1e5; i++) {    // O(1e5)
            for (int t = 0; t <= 1; t++) {
                ll palin = buildPalin(i, t);
                if (palin > 1e9)    continue;
                ll superPalin = palin * palin;
                if (superPalin >= lo && superPalin <= hi && isPalin(superPalin))
                    cnt++;
            }
        }
        return cnt;
    }
    
private:
    ll buildPalin(int i, int t) {    // O(l), l => the length of the number i
        ll res = i;
        if (t == 1)    i /= 10;    // Remove the last digit in i
        while (i > 0) {
            int lastDigit = i % 10;    i /= 10;
            res = res * 10 + lastDigit;
        }
        return res;
    }
    
    bool isPalin(ll num) {    // O(1)
        string s = to_string(num);
        string rs = s;
        reverse(rs.begin(), rs.end());
        return s == rs;
    }
};