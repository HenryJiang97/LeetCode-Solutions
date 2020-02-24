class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> bit(n);
        int MAX = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (char c : words[i])
                bit[i] |= 1 << (c - 'a');
            for (int j = i + 1; j < n; j++) {
                if (!(bit[i] & bit[j])) {
                    int prod = words[i].length() * words[j].length();
                    MAX = max(MAX, prod);
                }
            }
        }
        return MAX;
    }
};