class Solution {
    int i = 0;
public:
    string countOfAtoms(string formula) {
        map<string, int> cnt = helper(formula);
        
        // Get result
        string res = "";
        for (auto& [k, v] : cnt)
            res += k + (v > 1 ? to_string(v) : "");
        return res;
    }
    
private:
    map<string, int> helper(string formula) {    // Get the count of atoms
        map<string, int> cnt;
        string atom = "";
        while (i < formula.length()) {
            char c = formula[i];
            if (c == '(') {
                i++;
                map<string, int> inBracket = helper(formula);
                add(cnt, inBracket, formula);
            } else if (c == ')') {
                i++;
                return cnt;
            } else if (isdigit(c)) {
                int amount = 0;
                while (i < formula.length() && isdigit(formula[i])) {
                    amount = amount * 10 + (formula[i] - '0');
                    i++;
                }
                cnt[atom] += amount;
                atom = "";
            } else {
                atom += c;
                i++;
                while (i < formula.length() && formula[i] >= 'a' && formula[i] <= 'z') {
                    atom += formula[i];
                    i++;
                }
                if (i < formula.length() && !isdigit(formula[i])) {
                    cnt[atom]++;
                    atom = "";
                }
            }
        }
        if (atom != "")    cnt[atom]++;
        return cnt;
    }
    
    void add(map<string, int>& cnt, map<string, int>& m, string formula) {
        // Get atoms amount
        int amount = 0;
        while (isdigit(formula[i])) {
            amount = amount * 10 + (formula[i] - '0');
            i++;
        }
        
        // Add atoms in m to cnt
        for (auto& [k, v] : m)
            cnt[k] += v * amount;
    }
};