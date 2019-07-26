// Heap

class Solution {
    public String reorganizeString(String S) {
        int n = S.length();
        
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++)
            map.put(S.charAt(i) - 'a', map.getOrDefault(S.charAt(i) - 'a', 0) + 1);

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[1] - a[1]);
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            int key = entry.getKey(), val = entry.getValue();
            pq.offer(new int[]{key, val}); 
        }

        String res = "";
        int[] out = pq.poll();
        res += Character.toString((char)(out[0] + 'a'));
        if (--out[1] != 0)    pq.offer(out);
        
        while (!pq.isEmpty()) {
            int[] top = pq.peek();
            if (pq.size() == 1 && top[0] == res.charAt(res.length() - 1) - 'a')   return "";
            List<int[]> temp = new ArrayList<>();
            while (!pq.isEmpty()) {
                int[] arr = pq.poll();
                if (arr[0] != res.charAt(res.length() - 1) - 'a') {
                    res += Character.toString((char)(arr[0] + 'a'));
                    if (--arr[1] != 0)    temp.add(arr);
                    break;
                } else    temp.add(arr);
            }
            for (int[] a : temp)    pq.offer(a);    // Add items in temp back to queue
        }
        
        return res;
    }
}