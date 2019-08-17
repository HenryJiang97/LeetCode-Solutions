class Solution {
    int s;
    map<string, int> count;
    
public:
    string countOfAtoms(string formula) {
        s = formula.length() - 1;
        recurrsion(formula, 1);
        
        // Get result
        string res = "";
        for (auto entry : count)
            res += entry.first + (entry.second == 1 ? "" : to_string(entry.second));
        
        return res;
    }
    
private:
    void recurrsion(string formula, int multiple) {
        while (s >= 0) {
            if (isdigit(formula[s])) {
                // Get count of elements
                int num = 0, step = 1;
                while (isdigit(formula[s])) {
                    num += step * (formula[s] - '0');
                    step *= 10;    s--;
                }
                
                if (formula[s] == ')') {
                    s--;
                    recurrsion(formula, multiple * num);
                }  
                else {    // Atom with more than one element in current layer
                    string str = buildString(formula);
                    if (count.find(str) != count.end())    count[str] += multiple * num;
                    else    count[str] = multiple * num;
                    s--;
                }
            }
            
            else if (isalpha(formula[s])) {    // Atom with only one element in current layer
                string str = buildString(formula);
                if (count.find(str) != count.end())    count[str] += multiple;
                else    count[str] = multiple;
                s--;
            }
            
            else if (formula[s] == '(') {
                s--;    return;
            }
        }
    }
    
    // Build atom string
    string buildString(string formula) {
        string res = "";
        if (!islower(formula[s])) {
            res += formula[s];
            return res;
        } else {
            res = formula[s--] + res;
            res = formula[s] + res;
            return res;
        }
    }
};