struct cmp {
    bool operator()(vector<int>& c1, vector<int>& c2) {
        return abs(c1[0] - c1[1]) > abs(c2[0] - c2[1]);
    }
};

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        sort(costs.begin(), costs.end(), cmp());
        
        int A = 0, B = 0, cost = 0;
        for (int i = 0; i < n; i++) {
            if (A >= n / 2)    cost += costs[i][1];
            else if (B >= n / 2)    cost += costs[i][0];
            else {
                if (costs[i][0] > costs[i][1])    {B++;    cost += costs[i][1];}
                else    {A++;    cost += costs[i][0];}
            }
        }
        
        return cost;
    }
};