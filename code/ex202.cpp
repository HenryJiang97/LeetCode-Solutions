// Fast and slow pointers

class Solution {
public:
    bool isHappy(int n) {
        if (n == 1)    return 1;
        int fast = n, slow = n;
        while (1) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
            if (slow == 1)    return 1;
            if (slow == fast)    return 0;
        }
        return 0;
    }
    
private:
    int getNext(int n) {
        int sum = 0;
        while (n > 0) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
};