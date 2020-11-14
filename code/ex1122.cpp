class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size(), n2 = arr2.size();
        
        // Get count of elements in arr1
        map<int, int> cnt1;
        for (int a : arr1)    cnt1[a]++;
        
        vector<int> res;
        // Add elements in arr2
        for (int a : arr2) {
            for (int i = 0; i < cnt1[a]; i++) {
                res.push_back(a);
            }
            cnt1.erase(a);
        }
        
        // Add rest elements
        for (auto& [k, v] : cnt1) {
            for (int i = 0; i < v; i++) {
                res.push_back(k);
            }
        }
        
        return res;
    }
};