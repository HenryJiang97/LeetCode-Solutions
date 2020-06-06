class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();
        
        // Pre-process
        for (int i = n; i < 6; i++) {
            price.push_back(0);
            needs.push_back(0);
        }
        for (auto& s : special) {
            int p = s.back();
            s.pop_back();
            for (int i = n; i < 6; i++) {
                s.push_back(0);
            }
            s.push_back(p);
        }
        
        vector<vector<vector<vector<vector<vector<int>>>>>> dp(7, vector<vector<vector<vector<vector<int>>>>>(7, vector<vector<vector<vector<int>>>>(7, vector<vector<vector<int>>>(7, vector<vector<int>>(7, vector<int>(7, INT_MAX / 2))))));
        
        dp[0][0][0][0][0][0] = 0;
        for (int a = 0; a <= 6; a++) {   
            for (int b = 0; b <= 6; b++) {          
                for (int c = 0; c <= 6; c++) {
                    for (int d = 0; d <= 6; d++) {       
                        for (int e = 0; e <= 6; e++) {
                            for (int f = 0; f <= 6; f++) {
                                if (dp[a][b][c][d][e][f] == INT_MAX / 2)    continue;
                                if (a + 1 <= needs[0])
                                    dp[a + 1][b][c][d][e][f] = min(dp[a + 1][b][c][d][e][f], dp[a][b][c][d][e][f] + price[0]);
                                if (b + 1 <= needs[1])
                                    dp[a][b + 1][c][d][e][f] = min(dp[a][b + 1][c][d][e][f], dp[a][b][c][d][e][f] + price[1]);
                                if (c + 1 <= needs[2])
                                    dp[a][b][c + 1][d][e][f] = min(dp[a][b][c + 1][d][e][f], dp[a][b][c][d][e][f] + price[2]);
                                if (d + 1 <= needs[3])
                                    dp[a][b][c][d + 1][e][f] = min(dp[a][b][c][d + 1][e][f], dp[a][b][c][d][e][f] + price[3]);
                                if (e + 1 <= needs[4])
                                    dp[a][b][c][d][e + 1][f] = min(dp[a][b][c][d][e + 1][f], dp[a][b][c][d][e][f] + price[4]);
                                if (f + 1 <= needs[5])
                                    dp[a][b][c][d][e][f + 1] = min(dp[a][b][c][d][e][f + 1], dp[a][b][c][d][e][f] + price[5]);
                                
                                for (auto& s : special) {
                                    int na = a + s[0];
                                    int nb = b + s[1];
                                    int nc = c + s[2];
                                    int nd = d + s[3];
                                    int ne = e + s[4];
                                    int nf = f + s[5];
                                    
                                    if (na > needs[0] || 
                                        nb > needs[1] || 
                                        nc > needs[2] || 
                                        nd > needs[3] || 
                                        ne > needs[4] || 
                                        nf > needs[5])
                                        continue;
                                    
                                    dp[na][nb][nc][nd][ne][nf] = min(dp[na][nb][nc][nd][ne][nf], dp[a][b][c][d][e][f] + s[6]);
                                }
                            }
                        }
                    }
                }
            }
        }
        
        return dp[needs[0]][needs[1]][needs[2]][needs[3]][needs[4]][needs[5]];
    }
};