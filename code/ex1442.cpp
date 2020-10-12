// a ^ b = 0

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size(), cnt = 0;
        
        vector<int> prefix{0};
        for (int a : arr)    prefix.push_back(prefix.back() ^ a);
        
        for (int i = 0; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {                
                if (prefix[i] == prefix[j])
                    cnt += j - i - 1;
            }
        }
        
        return cnt;
    }
};