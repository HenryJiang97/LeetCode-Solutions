class Solution {
public:
    bool checkRecord(string s) {
        int A_num = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'A')    A_num++;
            if (A_num > 1)    return false;
            
            if (s[i] == 'L' && i - 2 >= 0 && s[i - 1] == 'L' && s[i - 2] == 'L')
                return false;
        }
        
        return true;
    }
};