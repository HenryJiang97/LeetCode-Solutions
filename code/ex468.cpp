class Solution {
private:
    // Method to split a string by a certain character
    vector<string> split(string s, char c) {
        vector<string> vec;
        string str = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == c) {
                vec.push_back(str);
                str = "";
            } else {
                str += s[i];
            }
        }
        if (str != "")    vec.push_back(str);
        if (s[s.length() - 1] == ':' || s[s.length() - 1] == '.')    vec.push_back("");
        return vec;
    }
    
public:
    string validIPAddress(string IP) {
        bool dot = false, colon = false;
        for (int i = 0; i < IP.length(); i++) {
            if (IP[i] == '.')    dot = true;
            if (IP[i] == ':')    colon = true;
        }
        // An IP address cannot have both dot and colon
        if (dot && colon)    return "Neither";
        
        // Test IPv4
        if (dot) {
            vector<string> addr = split(IP, '.');
            // IPv4 must have four segments
            if (addr.size() != 4)    return "Neither";
            
            for (auto& str : addr) {
                // Number length should between 1 and 3
                if (str.length() > 3 || str.length() == 0)    return "Neither";
                // '0' in the beginning is not allowed
                if (str.length() != 1 && str[0] == '0')    return "Neither";
                // Cannot have non-number in the string
                for (int i = 0; i < str.length(); i++)    if (str[i] < '0' || str[i] > '9')    return "Neither";
                // Each decimal number should between 0 and 255
                if (stoi(str) > 255 || stoi(str) < 0)    return "Neither";
            }
            return "IPv4";
        }
        
        // Test IPv6
        else if (colon) {
            vector<string> addr = split(IP, ':');
            // IPv6 must have eight segments
            if (addr.size() != 8)    return "Neither";
            
            for (auto & str : addr) {
                // Vacant segment or segment with number over 4 digits is not allowed
                if (str.length() > 4 || str.length() == 0)    return "Neither";
                // Only valid hexadecimal digits are allowed
                for (int i = 0; i < str.length(); i++)
                    if ((str[i] > 'F' && str[i] <= 'Z') || (str[i] > 'f' && str[i] <= 'z') || (str[i] == '-'))    return "Neither";
            }
            return "IPv6";
        } 
        
        // Neither IPv4 or IPv6
        else
            return "Neither";
    }
};