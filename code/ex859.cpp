class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.length() < 2 || A.length() != B.length())    return false;
        
        unordered_map<char, int> cnt;
        int diffchar = 0;
        vector<int> charidx;
        for (int i = 0; i < A.length(); i++) {
            cnt[A[i]]++;
            if (A[i] != B[i]) {
                diffchar++;
                charidx.push_back(i);
                if (diffchar > 2)    return false;
            }
        }
        
        if (diffchar != 0 && diffchar != 2)    return false;
        
        if (diffchar == 2) {
            int idx1 = charidx[0], idx2 = charidx[1];
            if (A[idx1] == B[idx2] && A[idx2] == B[idx1])    return true;
            else    return false;
        } else {
            int MAX = 0;
            for (auto entry : cnt) {
                MAX = max(MAX, entry.second);
            }
            return MAX >= 2 ? true : false;
        }
    }
};