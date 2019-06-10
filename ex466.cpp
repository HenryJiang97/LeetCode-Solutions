class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int l1 = s1.length(), l2 = s2.length();
        
        vector<int> indexarr(n1);  // Store the index of s2 at the beginning of each s1 block
        vector<int> cntarr(n1);  // Store the count of s2 at the beginning of each s1 block
        
        int p2 = 0, cnt = 0;
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < l1; j++) {
                if (s2[p2] == s1[j]) {
                    p2++;
                    if (p2 >= l2) {
                        p2 = 0;
                        cnt++;
                    }
                }
            }
            
            indexarr[i] = p2;
            cntarr[i] = cnt;
            
            for (int k = 0; k < i; k++) {
                if (indexarr[k] == p2) {
                    // Count the repeating times of s2 in s1
                    int before = cntarr[k];
                    int repeat = (cntarr[i] - cntarr[k]) * ((n1 - k - 1) / (i - k));
                    int remain = cntarr[k + (n1 - k - 1) % (i - k)] - cntarr[k];
                    return (before + repeat + remain) / n2;
                }
            }
        }
        
        // cout<<cnt;
        return cnt / n2;
    }
};