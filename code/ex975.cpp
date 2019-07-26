// DP, ordered_map: key=>the value at position i; value=>the next index

class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int n = A.size();
        vector<bool> dp_odd(n);
        vector<bool> dp_even(n);
        dp_odd[n - 1] = 1;    dp_even[n - 1] = 1;
        
        // Init treemap
        map<int, int> treemap;
        treemap[A[n - 1]] = n - 1;
        
        // Build dp arrays
        for (int i = n - 2; i >= 0; --i) {
            int key = A[i];
            if (treemap.find(key) != treemap.end()) {
                dp_odd[i] = dp_even[treemap[key]];
                dp_even[i] = dp_odd[treemap[key]];
            } else {
                auto iter1 = treemap.lower_bound(A[i]);   
                if (iter1 != treemap.end())
                {                
                    if (dp_even[iter1->second]) dp_odd[i] = true;
                }
            
                auto iter2 = treemap.upper_bound(A[i]);
                if (iter2 != treemap.begin())
                {
                    iter2 = prev(iter2,1);                
                    if (dp_odd[iter2->second]) dp_even[i] = true;
                }
            }
            treemap[key] = i;
        }
        
        // Get result
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += dp_odd[i];
        }
        return cnt;
    }
};