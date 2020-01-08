typedef long long ll;

class Solution {
    ll N;
    int cnt = 0, n;
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        this->N = N;    this->n = to_string(N).size();    // Digit of N
        if (N < stoll(D[0]))    return 0;
        
        for (int i = 1; i <= n - 1; i++)    // Count all possible numbers which has digit < n
            cnt += pow(D.size(), i);
        dfs(D, 0, 0);
        return cnt;
    }
    
private:
    void dfs(vector<string>& D, ll num, int s) {
        if (s == n) {
            cnt++;
            return;
        }
        
        for (int i = 0; i < D.size(); i++) {  
            if ('0' + stoi(D[i]) < to_string(N)[s]) {    // Do it mathematically
                cnt += pow(D.size(), n - s - 1);
            }
            else if ('0' + stoi(D[i]) == to_string(N)[s]) {
                ll newNum = num * 10 + stoll(D[i]);
                dfs(D, newNum, s + 1);
            }
        }
    }
};