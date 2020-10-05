class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0)    return 1;
        int d = 0;
        while ((1 << d) <= N)    d++;
        return N ^ ((1 << d) - 1);
    }
};