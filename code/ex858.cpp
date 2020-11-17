class Solution {
public:
    int mirrorReflection(int p, int q) {
        int x = lcd(p, q) / q;
        int y = lcd(p, q) / p;
        return y % 2 == 0 ? 0 : x % 2 == 0 ? 2 : 1;
    }
    
private:
    int lcd(int p, int q) {
        return p * q / GCD(p, q);
    }
    
    int GCD(int p, int q) {
        if (q == 0)    return p;
        return GCD(q, p % q);
    }
};