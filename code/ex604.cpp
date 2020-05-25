class StringIterator {
    string s;
    char c;
    int p, cnt, i;    // {global pointer, number of current char, index of current char}
    
public:
    StringIterator(string compressedString) {
        s = compressedString;
        p = 0;
        if (p < s.length())    getNextChar();
    }
    
    char next() {
        if (p >= s.length() && i >= cnt)    return ' ';
        else {
            char ret = c;
            if (++i >= cnt)    getNextChar();
            return ret;
        }
    }
    
    bool hasNext() {
        return p < s.length() || i < cnt;
    }
    
private:
    void getNextChar() {
        c = s[p++];
        i = 0;
        cnt = 0;
        while (p < s.length() && isdigit(s[p])) {
            cnt = cnt * 10 + (s[p] - '0');
            p++;
        }
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */