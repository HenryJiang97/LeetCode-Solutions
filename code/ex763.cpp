// Greedy

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> last(26);    // Last appearance of certain char
        for (int i = 0; i < S.length(); i++)    last[S[i] - 'a'] = i;
        
        // Greedy
        vector<int> len;
        int start = 0, end = last[S[0] - 'a'];
        
        for (int i = 1; i < S.length(); i++) {
            if (i > end) {
                len.push_back(end - start + 1);
                start = i;
                end = last[S[i] - 'a'];
            } else {
                end = max(end, last[S[i] - 'a']);
            }
        }
        
        len.push_back(end - start + 1);
        
        return len;
    }
};