// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += rand7() - 1;    // rand7() - 1 => [0, 6]
        }
        return sum % 10 + 1;
    }
};