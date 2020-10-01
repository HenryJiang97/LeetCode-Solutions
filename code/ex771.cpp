class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewery;
        for (char j : J)    jewery.insert(j);
        int cnt = 0;
        for (char c : S)    if (jewery.count(c) > 0)    cnt++;
        return cnt;
    }
};