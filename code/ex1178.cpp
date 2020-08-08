class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> cnt;
        for (string word : words) {
            int mask = 0;
            for (char c : word)    mask |= (1 << (c - 'a'));
            cnt[mask]++;
        }
        
        vector<int> res;
        for (string puzzle : puzzles) {
            int mask = 0;
            for (char c : puzzle)    mask |= (1 << (c - 'a'));
            
            int amount = 0;
            int substring = mask;
            int first = 1 << (puzzle[0] - 'a');
            while (1) {
                if ((substring & first) == first && cnt.count(substring) > 0)
                    amount += cnt[substring];
                if (substring == 0)    break;
                
                // Get next substring
                substring = (substring - 1) & mask;
            }
            
            res.push_back(amount);
        }
        
        return res;
    }
};