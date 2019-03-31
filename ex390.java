import java.util.*;

class Solution {
    public int lastRemaining(int n) {
        List<Integer> list = new ArrayList<>();
        for (int i = 1; i <= n; i++)    list.add(i);
        
        while (list.size() > 1) {
            int i = 0;
            while (i < list.size()) {
                list.remove(i);
                i += 2;
            }
            Collections.reverse(list);
        }
        
        return list.get(0);
    }
}