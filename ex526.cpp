// Backtracking

class Solution {
public:
    int countArrangement(int N) {
        int cnt = 0;
        bool visited[N + 1] = {false};
        backtracking(N, 1, cnt, visited);
        return cnt;
    }
    
private:
    void backtracking(int N, int pos, int& cnt, bool visited[]) {
        if (pos > N)    {cnt++; return;}
        
        for (int i = 1; i <= N; i++) {
            if (visited[i])    continue;
            visited[i] = true;
            
            if ((i % pos == 0) || (pos % i == 0))
                backtracking(N, pos + 1, cnt, visited);
            
            visited[i] = false;
        }
    }
};