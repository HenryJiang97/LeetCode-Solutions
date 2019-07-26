// Hash Table

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size())    return {};
        vector<int> res;
    
        // Add characters in p to hash table
        unordered_map<char, int> map;
        for (char c : p) {
            if (map.find(c) != map.end())    map[c] = map[c] + 1;
            else    map[c] = 1;
        }
        
        int zeros = map.size();
        
        // Get the first p.size() char
        for (int i = 0; i < p.size(); i++) {
            if (map.find(s[i]) != map.end()) {
                map[s[i]]--;
                if (map[s[i]] == 0)    zeros--;
            }
        }
        if (zeros == 0)    res.push_back(0);
        
        // Iterate the rest of the array
        for (int i = p.size(); i < s.size(); i++) {
            // Add new end char to the map
            if (map.find(s[i]) != map.end()) {
                map[s[i]]--;
                if (map[s[i]] == 0)    zeros--;
            }
            
            // Head char has been removed from the sliding window
            char head = s[i - p.size()];
            if (map.find(head) != map.end()) {
                if (map[head] == 0)    zeros++;
                map[head]++;
            }
            
            if (zeros == 0)    res.push_back(i - p.size() + 1);
        }
        
        return res;
    }
};