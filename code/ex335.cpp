class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        if (x.size() <= 3)    return false;
        
        
        for (int i = 3; i < x.size(); i++) {
            // Fourth line cross the first line
            if (x[i - 1] <= x[i - 3] && x[i] >= x[i - 2])    return true;
            
            // Fifth line meets first line
            if (i >= 4 && x[i - 3] == x[i - 1] && x[i - 4] + x[i] >= x[i - 2])    return true;
      
            // Sixth line meets first line
            if (i >= 5 && x[i - 1] <= x[i - 3] && x[i - 4] + x[i] >= x[i - 2] && x[i - 1] + x[i - 5] >= x[i - 3] && x[i - 2] > x[i - 4])    return true;
        }
        
        return false;
    }
};