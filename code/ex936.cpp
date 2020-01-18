class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int ns = stamp.size(), nt = target.size();
        
        vector<int> res;
        string backup = "";
        while (backup != target) {
            backup = target;

            for (int l = ns; l > 0; l--) {
                for (int i = 0; i <= ns - l; i++) {    // Get new stamp
                    string newStamp = string(i, '?') + stamp.substr(i, l) + string(ns - i - l, '?');
                    int pos = target.find(newStamp);
                    while (pos != string::npos) {
                        for (int k = 0; k < ns; k++) {    // Replace target with new stamp
                            target[k + pos] = '?';
                        }
                        res.push_back(pos);
                        pos = target.find(newStamp);
                    }
                }
            }
        }
        
        string desired = "";
        for (int i = 0; i < nt; i++)    desired += '?';
        
        reverse(res.begin(), res.end());
        return target == desired ? res : vector<int>();
    }
};