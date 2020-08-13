class CombinationIterator {
    void generate(string s, int len, vector<string>& comb, string cur, int start) {
        if (len == 0) {
            comb.push_back(cur);
            return;
        }
        for (int i = start; i < s.length(); i++) {
            generate(s, len - 1, comb, cur + s[i], i + 1);
        }
    }
    
public:
    vector<string> comb;
    int i = 0;
    
    CombinationIterator(string characters, int combinationLength) {
        generate(characters, combinationLength, comb, "", 0);
    }
    
    string next() {
        return comb[i++];
    }
    
    bool hasNext() {
        return i < comb.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */