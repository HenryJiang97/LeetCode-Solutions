import java.util.*;

class Solution {
    public int bitwiseComplement(int N) {
        if (N == 0)    return 1;
        
        List<Integer> list = new ArrayList<>();
        
        while (N != 0) {
            if (N % 2 == 0)    list.add(1);
            else    list.add(0);
            N /= 2;
        }

        
        int res = 0;
        for (int i = 0; i < list.size(); i++) {
            res += Math.pow(2, i) * list.get(i);
        }
        
        return res;
    }
}