class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();    if (n <= 1)    return n;
        
        int MAX = 2;
        for (int i = 0; i < n; i++) {
            auto p1 = points[i];
            int x1 = p1[0], y1 = p1[1];
            int duplicates = 0;
            unordered_map<int, unordered_map<int, int>> map;    // {numerator, {denominator, cnt}}
            
            for (int j = 0; j < n; j++) {
                auto p2 = points[j];
                int x2 = p2[0], y2 = p2[1];
                if (x1 == x2 && y1 == y2) {
                    duplicates++;
                    continue;
                }
                
                // Get numerator and denominator of the slope and counts
                int numerator = y1 - y2, denominator = x1 - x2;
                int gcd = getGCD(numerator, denominator);
                if (gcd != 0) {
                    numerator /= gcd;
                    denominator /= gcd;
                }
                if (numerator < 0) {
                    numerator /= -1;
                    denominator /= -1;
                }
                map[numerator][denominator]++;
            }
            
            MAX = max(MAX, duplicates);
            for (auto entry1 : map)
                for (auto entry2 : entry1.second)
                    MAX = max(MAX, entry2.second + duplicates);
        }
        
        return MAX;
    }
    
    int getGCD(int a, int b) {
        if (b == 0)    return a;
        return gcd(b, a % b);
    }
};