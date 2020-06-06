struct cmp {
    bool operator()(vector<int>& a, vector<int>& b) {
        if (a[0] != b[0])    return a[0] < b[0];
        else if (a[1] != b[1])    return a[1] < b[1];
        else if (a[2] != b[2])    return a[2] < b[2];
        else if (a[3] != b[3])    return a[3] < b[3];
        else if (a[4] != b[4])    return a[4] < b[4];
        else    return a[5] < b[5];
    }
};

class LogSystem {
    vector<vector<int>> arr;
    
public:
    LogSystem() {
        
    }
    
    void put(int id, string timestamp) {
        vector<int> time = split(timestamp);
        time.push_back(id);
        arr.push_back(time);
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        sort(arr.begin(), arr.end(), cmp());
        
        vector<int> S = split(s);
        vector<int> E = split(e);
        
        vector<int> ids;
        int i = 0;
        while (i < arr.size() && compare(arr[i], S, gra) < 0)    i++;
        while (i < arr.size() && compare(arr[i], S, gra) >= 0 && compare(arr[i], E, gra) <= 0) {
            ids.push_back(arr[i][6]);
            i++;
        }
        return ids;
    }

private:
    vector<int> split(string timestamp) {
        timestamp += ':';
        vector<int> res;
        string temp = "";
        for (char c : timestamp) {
            if (c == ':') {
                res.push_back(stoi(temp));
                temp = "";
            } else {
                temp += c;
            }
        }
        return {res[0], res[1], res[2], res[3], res[4], res[5]};
    }
    
    int compare(vector<int>& a, vector<int>&b, string gra) {
        int n = 0;
        if (gra == "Year")    n = 0;
        else if (gra == "Month")    n = 1;
        else if (gra == "Day")    n = 2;
        else if (gra == "Hour")    n = 3;
        else if (gra == "Minute")    n = 4;
        else    n = 5;
        
        for (int i = 0; i <= n; i++) {
            if (a[i] != b[i]) {
                return a[i] < b[i] ? -1 : 1;
            }
        }
        
        return 0;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(s,e,gra);
 */