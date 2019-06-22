class Solution {
    public int magicalString(int n) {
        if (n == 0)    return 0;
        int cnt = 0;
        // Build the magic string
        int[] magicstr = new int[n];    magicstr[0] = 1;
        int fast = 0, slow = 0, sign = 1;  // sign == 1 or 2 represent the next occurance of 1 and 2
        while (fast < n) {
            if (magicstr[slow++] == 1) {
                magicstr[fast++] = (sign == 1) ? 1 : 2;
                cnt++;
            } else {
                magicstr[fast++] = (sign == 1) ? 1 : 2;
                if (fast < n)    magicstr[fast++] = (sign == 1) ? 1 : 2;
            }
            sign = (sign == 1) ? 2 : 1;    // Inverse the state
        }
        
        for (int i = slow; i < n; i++)
            if (magicstr[i] == 1)    cnt++;
        
        return cnt;
    }
}