class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, vector<int>> map;
        for (int i = 0; i < s.length(); i++)
            map[s[i]].push_back(i);
        
        int firstIdx = s.length();
        for (auto entry : map)
            if (entry.second.size() == 1)
                if (entry.second[0] < firstIdx)
                    firstIdx = entry.second[0];
        
        return firstIdx == s.length() ? -1 : firstIdx;
    }
};