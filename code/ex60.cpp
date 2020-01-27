class Solution {
public:
    string getPermutation(int n, int k) {
        k--;
        string res = "";
        int total = factorial(n);    // Number of digit candidates, total choices on current digit
        unordered_set<int> available;    // All available digit candidates
        for (int i = 1; i <= n; i++)    available.insert(i);    // Get all candidates
        
        for (int d = 0; d < n; d++) {
            int loop = total / available.size();
            int i = k / loop;
            k = k % loop;    // The kth item in current loop
            // Get the actural digit
            int cnt = 0;
            for (int digit = 1; digit <= n; digit++) {
                if (available.count(digit) == 0)    continue;
                if (cnt == i)    {
                    res += to_string(digit);
                    available.erase(digit);
                    break;
                }
                cnt++;
            }
            total = loop; 
        }
        
        return res;
    }
    
private:
    int factorial(int n) {
        int res = 1;
        for (int i = n; i > 1; i--)
            res *= i;
        return res;
    }
};