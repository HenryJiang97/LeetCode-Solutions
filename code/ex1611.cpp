class Solution {
public:
    int minimumOneBitOperations(int n) {
        string s = bitset<32>(n).to_string();
        return backtracking(s);
    }
    
private:
    unordered_map<string, int> memo1;
    unordered_map<string, int> memo2;
    
    int backtracking(string s) {
        if (s == "")    return 0;
        if (memo1.count(s) > 0)    return memo1[s];
        
        if (s[0] == '0')    return memo1[s] = backtracking(s.substr(1));
        
        string ss = s.substr(1);
        int steps = getSteps(s.substr(1));
        ss[0] = '1';
        for (int i = 1; i < ss.length(); i++) {
            ss[i] = '0';
        }
        return memo1[s] = backtracking(ss) + steps + 1;
    }
    
    int getSteps(string s) {    // Get the steps for string to change to "1000000..." form
        if (s == "")    return 0;
        if (memo2.count(s) > 0)    return memo2[s];
        
        if (s[0] == '1')    return backtracking(s.substr(1));
        
        int steps = getSteps(s.substr(1));
        string ss = s.substr(1);
        ss[0] = '1';
        for (int i = 1; i < ss.length(); i++) {
            ss[i] = '0';
        }
        return memo2[s] = steps + backtracking(ss) + 1;
    }
};