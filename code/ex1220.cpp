class Solution {
public:
    int countVowelPermutation(int n) {
        int mod = 1e9 + 7;
        int dpa = 1, dpe = 1, dpi = 1, dpo = 1, dpu = 1;
        
        for (int i = 2; i <= n; i++) {
            int bka = dpa, bke = dpe, bki = dpi, bko = dpo, bku = dpu;
            dpa = bke % mod;
            dpe = (bka + bki) % mod;
            dpi = (((bka + bke) % mod + bko) % mod + bku) % mod;
            dpo = (bki + bku) % mod;
            dpu = bka % mod;
        }
        
        return ((((dpa + dpe) % mod + dpi) % mod + dpo) % mod + dpu) % mod;
    }
};