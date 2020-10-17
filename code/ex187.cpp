class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<char, int> dict{{'A', 1}, {'C', 2}, {'G', 3}, {'T', 4}};
        unordered_set<long> set;
        
        // Init hash
        long hash = 0;
        for (int i = 0; i < 10; i++) {
            hash = hash * 5 + dict[s[i]];
        }
        set.insert(hash);
        
        // Rehashing through the string
        unordered_set<string> resSet;
        for (int hi = 10; hi < s.length(); hi++) {
            int lo = hi - 10;
            hash -= dict[s[lo++]] * (long)pow(5, 9);
            hash = hash * 5 + dict[s[hi]];
            if (set.count(hash) > 0) {
                resSet.insert(s.substr(lo, 10));
            }
            set.insert(hash);
        }
        
        return vector<string>(resSet.begin(), resSet.end());
    }
};