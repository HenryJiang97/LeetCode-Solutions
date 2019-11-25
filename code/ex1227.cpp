class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        return n == 1 ? 1.0 : 0.5;
    }
};


// Follow up
// The probability of the kth person who can get his seat
// 1 / (n - (k - 2)) => the probability of a person whose seat has been occupied by others