class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> f2;
        for (int i = 0; i < list2.size(); i++)    f2[list2[i]] = i;
        
        int MIN = list1.size() + list2.size();
        vector<string> res;
        for (int i = 0; i < list1.size(); i++) {
            if (f2.count(list1[i]) != 0) {
                if (i + f2[list1[i]] == MIN)
                    res.push_back(list1[i]);
                else if (i + f2[list1[i]] < MIN) {
                    res.clear();
                    res.push_back(list1[i]);
                    MIN = i + f2[list1[i]];
                }
            }
        }
        
        return res;
    }
};