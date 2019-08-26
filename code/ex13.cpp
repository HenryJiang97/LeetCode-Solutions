class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        vector<int> dict(26);
        dict['I' - 'A'] = 1;
        dict['V' - 'A'] = 5;
        dict['X' - 'A'] = 10;
        dict['L' - 'A'] = 50;
        dict['C' - 'A'] = 100;
        dict['D' - 'A'] = 500;
        dict['M' - 'A'] = 1000;
        
        int sum = 0;
        
        int i = 0;
        for (i = 0; i < n - 1; i++) {
            if (dict[s[i] - 'A'] < dict[s[i + 1] - 'A']) {
                sum += dict[s[i + 1] - 'A'] - dict[s[i] - 'A'];
                i++;
            } else {
                sum += dict[s[i] - 'A'];
            }
        }
        if (i < n)    sum += dict[s[i] - 'A'];
        
        return sum;
    }
};