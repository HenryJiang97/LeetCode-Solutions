#include<vector>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int pg = 0, ps = 0, cnt = 0;
        while (pg < g.size() && ps < s.size()) {
            if (s[ps] >= g[pg]) {
                cnt++;
                ps++;    pg++;
            } else {
                ps++;
            }
        }
        return cnt;
    }
};