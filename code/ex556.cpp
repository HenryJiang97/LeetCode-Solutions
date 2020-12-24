class Solution {
public:
    int nextGreaterElement(int n) {
        long nxt = stol(nextPermutation(to_string(n)));
        return nxt > INT_MAX ? -1 : (int)nxt;
    }
    
private:
    string nextPermutation(string s) {
        int n = s.length();
        
        int a = n - 2;
        while (a >= 0 && s[a] >= s[a + 1])    a--;
        if (a < 0)    return "-1";
        
        int b = n - 1;
        while (b > a && s[b] <= s[a])    b--;
        if (b <= a)    return "-1";
        
        swap(s[a], s[b]);
        
        int lo = a + 1, hi = n - 1;
        while (lo < hi) {
            swap(s[lo++], s[hi--]);
        }
        
        return s;
    }
};