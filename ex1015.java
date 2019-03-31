class Solution {
    public int smallestRepunitDivByK(int K) {
        if (K % 2 == 0 || K % 5 == 0)    return -1;
        
        int len = 1;
        int n = 0;
        while (len <= K) {
            n = (n * 10 + 1) % K;
            if (n == 0)    return len;
            len++;            
        }
        
        return -1;
    }
}