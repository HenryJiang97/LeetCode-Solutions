import java.util.*;

class Solution {
    public void list_builder(List<Integer> res, int n, int num) {
        int origin_num = num * 10;
        num = origin_num;
        
        for (int i = 0; i <= 9; i++) {
            if (num + i <= n) {
                res.add(num + i);
                list_builder(res, n, num + i);
                num = origin_num;    // Restore to origin number of current recursion
            } else
                return;            
        }
    }
    
    public List<Integer> lexicalOrder(int n) {
        List<Integer> res = new ArrayList<>();
        int num = 0;

        for (int i = 1; i <= 9; i++) {
            if (num + i <= n) {
                res.add(num + i);
                list_builder(res, n, num + i);
                num = 0;    // Restore to origin number 0
            } else
                break;            
        }

        return res;
    }
}