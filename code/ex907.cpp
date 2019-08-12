// sum = A[0 : n - 1] * ((left + 1) * (right + 1))
// Maintaining monotone ascending stack

class Solution {
    int mod = 1e9 + 7;
public:
    int sumSubarrayMins(vector<int>& A) {
        int n = A.size();
        
        stack<pair<int, int>> sleft, sright;    // {value, count} pair
        vector<int> vleft(n), vright(n);
        
        // Calculate from the left
        for (int i = 0; i < n; i++)
        {
            int cnt = 1;
            while (!sleft.empty() && sleft.top().first > A[i])
            {
                cnt += sleft.top().second;    sleft.pop();
            }
            sleft.push({A[i], cnt});
            vleft[i] = cnt;
        }
        
        // Calculate from the right
        for (int i = n - 1; i >= 0; --i)
        {
            int cnt = 1;
            while (!sright.empty() && sright.top().first >= A[i])
            {
                cnt += sright.top().second;    sright.pop();
            }
            sright.push({A[i], cnt});
            vright[i] = cnt;
        }
        
        // Get the result
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum = (sum + A[i] * vleft[i] * vright[i]) % mod;
        
        return sum;
    }
};