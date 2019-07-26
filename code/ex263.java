class Solution {
    public boolean isUgly(int num) {
        // Special situation
        if (num == 0)   return false;
        if (num == 1)   return true;
        
        // Divide num by 2
        while (num % 2 == 0) {
            num /= 2;
            if (num == 1)   return true;
        }

        // Divide num by 3
        while (num % 3 == 0) {
            num /= 3;
            if (num == 1)   return true;
        }

        // Divide num by 5
        while (num % 5 == 0) {
            num /= 5;
            if (num == 1)   return true;
        }

        return false;
    }
}