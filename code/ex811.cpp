class Solution {
    unordered_map<string, int> map;
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        for (string domain : cpdomains)
            process(domain);
        vector<string> res;
        for (auto& [k, v] : map)
            res.push_back(to_string(v) + " " + k);
        return res;
    }
    
private:
    void process(string domain) {
        int cnt, p = 0;
        string temp = "";
        while (1) {
            char c = domain[p++];
            if (c == ' ') {
                cnt = stoi(temp);
                break;
            } else {
                temp += c;
            }
        }
        
        temp = "";
        for (int i = domain.length() - 1; i >= p; i--) {
            char c = domain[i];
            if (c == '.') {
                map[temp] += cnt;
            }
            temp = c + temp;
        }
        if (temp != "")    map[temp] += cnt;
    }
};