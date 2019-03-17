// Heap

import java.util.*;

class Solution {
    public int findKthLargest(int[] nums, int k) {
        Queue<Integer> pq = new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare (Integer a, Integer b) {
                if (a > b)    return -1;
                else    return 1;
            }
        });
        
        for (int num : nums)
            pq.offer(num);
        
        for (int i = 1; i < k; i++)
            pq.poll();

        
        return pq.poll();
    }
}