import java.util.*;

class Solution {
    public List<Boolean> prefixesDivBy5(int[] A) {
        List<Boolean> res = new ArrayList<>();
        
        int num = 0;
        
        for (int i = 0; i < A.length; i++) {
            num = (num * 2 + A[i]) % 5;
            if (num == 0) {
                res.add(true);
            }
            else    res.add(false);
        }
        
        return res;
    }
}