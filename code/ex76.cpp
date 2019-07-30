// Sliding window

class Solution {
public:
    string minWindow(string s, string t) {
        int start = -1, end = -1, MIN = s.length() + 1;
        
        unordered_map<char, int> map;    // Store the appearance of each character in the sliding window
        unordered_map<char, int> set;    // Store the appearance of each character in string t
        for (char c : t) {
            map[c] = 0;
            set[c] = set.find(c) != set.end() ? set[c] + 1 : 1;
        }
        int n = set.size();

        // Sliding window
        int e = 0;    // Needed element in the sliding window
        int left = 0, right = 0;
        while (right < s.length()) {
            // Shift the right pointer right
            if (set.find(s[right]) != set.end()) {
                if (map[s[right]] < set[s[right]] && map[s[right]] + 1 >= set[s[right]])    e++;
                map[s[right]]++;
            }

            // Shift the left pointer right
            while (e == n && left <= right) {
                // Once all char in t appears in the map, update start and end
                int interval = right - left + 1;
                if (interval < MIN) {
                    start = left;    end = right;
                    MIN = interval;
                }
                //
                
                if (set.find(s[left]) != set.end()) {
                    if (--map[s[left]] < set[s[left]])    e--;
                }
                left++;
            }
            
            right++;
        }
        
        return start == -1 ? "" : s.substr(start, end - start + 1);
    }
};