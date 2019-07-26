class Solution {
public:
    int maximumSwap(int num) {
        string n = to_string(num);
        
        for (int i = 0; i < n.length(); i++) {
            int max_idx = i;
            char MAX = n[i];
            
            // Find the maximum digit larger than n[i] and locates at the most end part of the number
            for (int j = i + 1; j < n.length(); j++) {
                if (n[j] >= MAX) {
                    MAX = n[j];
                    max_idx = j;
                }
            }
            
            // Swap
            if (MAX != n[i]) {
                n[max_idx] = n[i];
                n[i] = MAX;
                break;
            }
        }
        
        return stoi(n);
    }
};