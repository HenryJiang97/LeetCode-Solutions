// Insert people from tall to short.
// Insert each person at the position where there are k people in front of him who are either samme hight as this person or blank position currently.

import java.util.*;

class Solution {
    class my_comparator implements Comparator<int[]>{
        @Override
        public int compare(int[] a, int[] b) {
            if (a[0] != b[0])    return b[0] - a[0];
            else    return a[1] - b[1];
        }
    };
    
    public int[][] reconstructQueue(int[][] people) {
        Arrays.sort(people, new my_comparator());
        
        List<int[]> list = new ArrayList<>();
        
        for (int[] p : people) {
            list.add(p[1], p);
        }
        
        return list.toArray(new int[people.length][2]);
    }
}