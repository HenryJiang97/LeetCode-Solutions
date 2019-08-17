// Line Sweep, Heap

typedef pair<int, int> ii;

class Solution {
    struct cmp {    // Custom sort
        bool operator()(ii a, ii b) {
            if (a.first != b.first)    return a.first < b.first;    // First sort buildings by their x-corrdinate
            else {
                if (a.second < 0 && b.second < 0)
                    return -a.second > -b.second;    // If two buildings has the same starting x, sort y in descending order
                else if (a.second > 0 && b.second > 0)
                    return a.second < b.second;    // If two buildings has same ending x, sort y in ascending order
                else    return a.second < b.second;    // If two buildings align together side by side, put up edge before down edge
            } 
        }
    };
    
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // Get a sorted map by the x-corrdinate of each building
        vector<ii> map;
        for (auto building : buildings) {
            map.push_back({building[0], -building[2]});    // Up edge, store the height with negative value
            map.push_back({building[1], building[2]});    // Down edge, store the height with positive value
        }
        sort(map.begin(), map.end(), cmp());
        
        
        vector<vector<int>> res;
        multiset<int> ms;    ms.insert(0);
        int prev = 0, cur = 0;
        
        for (auto b : map) {
            if (b.second < 0) {    // Up edge
                if (-b.second > *ms.rbegin())
                    res.push_back({b.first, -b.second});
                ms.insert(-b.second);
            }
            else {    // Down edge
                ms.erase(ms.find(b.second));
                if (b.second > *ms.rbegin())
                    res.push_back({b.first, *ms.rbegin()});
            }
        }
        
        return res;
    }
};