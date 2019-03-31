class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        // Get the sum of the array
        int sum = 0;
        for (int a : A)    sum += a;
        
        // Get the sum of each partition
        if (sum % 3 != 0)    return false;
        int part = sum / 3;
        
        int s = 0, cnt = 0;
        for (int i = 0; i < A.length; i++) {
            s += A[i];
            if (s == part) {
                s = 0;    cnt++;
            }
        }
        
        return (cnt == 3) ? true : false;
    }
}