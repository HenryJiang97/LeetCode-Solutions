typedef long long ll;

class Solution {
    vector<int> validDigits = {0, 1, 6, 8, 9};
    vector<int> map = {0, 1, 2, 3, 4, 5, 9, 7, 8, 6};
    int cnt = 0;
    
public:
    int confusingNumberII(int N) {
        backtracking(N, 0);
        return cnt;
    }
    
private:
    void backtracking(int N, ll num) {
        if (num > N)    return;
        if (isConfusing(num))    cnt++;
        for (int v : validDigits) {
            if (num == 0 && v == 0)    continue;
            backtracking(N, num * 10 + v);
        }
    }
    
    bool isConfusing(ll num) {
        string n = to_string(num);
        for (int i = 0; i < n.length(); i++) {
            if ((n[i] - '0') != map[n[n.length() - i - 1] - '0'])
                return 1;
        }
        return 0;
    }
};