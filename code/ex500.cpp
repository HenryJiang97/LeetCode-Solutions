class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> set1, set2, set3;
        set1.insert('Q');    set2.insert('A');     set3.insert('Z');
        set1.insert('W');    set2.insert('S');     set3.insert('X');
        set1.insert('E');    set2.insert('D');     set3.insert('C');
        set1.insert('R');    set2.insert('F');     set3.insert('V');
        set1.insert('T');    set2.insert('G');     set3.insert('B');
        set1.insert('Y');    set2.insert('H');     set3.insert('N');
        set1.insert('U');    set2.insert('J');     set3.insert('M');
        set1.insert('I');    set2.insert('K');
        set1.insert('O');    set2.insert('L');
        set1.insert('P');

        vector<string> res;
        for (string& word : words) {
            bool sign = true;
            
            if (set1.find(word[0]) != set1.end() || set1.find(word[0] - 32) != set1.end()) {
                for (int i = 1; i < word.length(); i++) {
                    if (set1.find(word[i]) == set1.end() && set1.find(word[i] - 32) == set1.end())
                        sign = false;
                }
            } else if (set2.find(word[0]) != set2.end() || set2.find(word[0] - 32) != set2.end()) {
                for (int i = 1; i < word.length(); i++) {
                    if (set2.find(word[i]) == set2.end() && set2.find(word[i] - 32) == set2.end())
                        sign = false;
                }
            } else if (set3.find(word[0]) != set3.end() || set3.find(word[0] - 32) != set3.end()) {
                for (int i = 1; i < word.length(); i++) {
                    if (set3.find(word[i]) == set3.end() && set3.find(word[i] - 32) == set3.end())
                        sign = false;
                }
            } else    sign = false;
            
            if (sign)    res.push_back(word);
        }

        return res;
    }
};