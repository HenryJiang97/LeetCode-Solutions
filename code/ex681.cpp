class Solution {
public:
    string nextClosestTime(string time) {
        vector<char> chars{time[0], time[1], time[3], time[4]};
        
        vector<string> choices;
        string res = "24:00";
        for (char c1 : chars) {
            for (char c2 : chars) {
                for (char c3 : chars) {
                    for (char c4 : chars) {
                        if (!ifValid(c1, c2, c3, c4))    continue;
                        string s = "";
                        s = s + c1 + c2 + ":" + c3 + c4;
                        choices.push_back(s);
                        if (s > time && s < res) {
                            res = s;
                        }
                    }
                }
            }
        }
        
        if (res < "24:00")    return res;
        sort(choices.begin(), choices.end());
        return choices[0];
    }
    
private:
    bool ifValid(char c1, char c2, char c3, char c4) {
        string hour = "", minute = "";
        hour = hour + c1 + c2;
        minute = minute + c3 + c4;
        int nh = stoi(hour), nm = stoi(minute);
        return (nh >= 0 && nh <= 23 && nm >= 0 && nm <= 59);
    }
};