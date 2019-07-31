// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        // Since there's at most one celebrity, pick out one which is known by others
        int candidate = 0;
        for (int i = 1; i < n; i++) {
            if (knows(candidate, i))    candidate = i;
        }
        
        // Varify if the candidate is valid (Known by anyone)
        for (int i = 0; i < n; i++) {
            if (!knows(i, candidate))    return -1;
            if (knows(candidate, i) && candidate != i)    return -1;
        }
        
        return candidate;
    }
};