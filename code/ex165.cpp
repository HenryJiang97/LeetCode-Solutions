class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> a1 = split(version1);
        vector<int> a2 = split(version2);
        int n1 = a1.size(), n2 = a2.size(), p1 = 0, p2 = 0;
        while (p1 < n1 && p2 < n2) {
            if (a1[p1] < a2[p2])    return -1;
            else if (a1[p1] > a2[p2])    return 1;
            else {
                p1++;    p2++;
            }
        }
        return n1 > n2 ? 1 : n1 == n2 ? 0 : -1;
    }
    
private:
    vector<int> split(string s1) {
        vector<int> res;
        s1 += '.';
        int temp = 0;
        for (char c : s1) {
            if (c == '.') {
                res.push_back(temp);
                temp = 0;
            } else {
                temp = temp * 10 + (c - '0');
            }
        }
        while (!res.empty() && res.back() == 0)    res.pop_back();
        return res;
    }
};