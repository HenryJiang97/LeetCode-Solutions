class Solution {
    public String largestTimeFromDigits(int[] A) {
        int n = A.length;
        String res = "";
        int max = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    for (int l = 0; l < n; l++) {
                        if (i == j || i == k || i == l || j == k || j == l || k == l)
                            continue;
                        if (valid(A[i], A[j], A[k], A[l])) {
                            if (A[l] + A[k] * 10 + A[j] * 100 + A[i] * 1000 >= max) {
                                max = A[l] + A[k] * 10 + A[j] * 100 + A[i] * 1000;
                                res = String.valueOf(A[i]) + String.valueOf(A[j]) + ":" + String.valueOf(A[k]) + String.valueOf(A[l]);
                            }
                        }
                    }
                }
            }
        }
        
        return res;
    }
    
    private boolean valid(int i, int j, int k, int l) {
        if (i > 2 || k > 5)    return false;
        if (i == 2 && j > 3)    return false;
        return true;
    }
}