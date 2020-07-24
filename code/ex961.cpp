class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int> set;
        for (int a : A)
            if (set.count(a) > 0)    return a;
            else    set.insert(a);
        return A.back();
    }
};