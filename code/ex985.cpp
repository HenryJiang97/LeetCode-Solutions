class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int n = A.size();
        int odd = 0, even = 0;
        for (int a : A) {
            if (a % 2 == 0)    even += a;
            else    odd += a;
        }
        
        vector<int> res;
        for (auto& query : queries) {
            int val = query[0], idx = query[1];
            if (A[idx] % 2 == 0) {
                if (val % 2 == 0) {    // Even to even
                    even += val;
                } else {    // Even to odd
                    even -= A[idx];
                    odd += (A[idx] + val);
                }
            } else {
                if (val % 2 == 0) {    // Odd to odd
                    odd += val;
                } else {    // Odd to even
                    odd -= A[idx];
                    even += (A[idx] + val);
                }
            }
            A[idx] += val;
            res.push_back(even);
        }
        
        return res;
    }
};