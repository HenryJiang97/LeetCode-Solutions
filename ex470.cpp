// Rejection Sampling (拒绝采样)

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        // Gets random number between 1 and 49(7 * 7)
        int rand = INT_MAX;
        while (rand > 40) {
            int col = rand7();
            int row = rand7();
            rand = 7 * (row - 1) + col;
        }
        
        return rand % 10 + 1;
    }
};