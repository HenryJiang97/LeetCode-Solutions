class Solution {
    public int[][] highFive(int[][] items) {
        TreeMap<Integer, PriorityQueue<Integer>> tmap = new TreeMap<>();
        for (int[] item : items) {
            int id = item[0], score = item[1];
            PriorityQueue<Integer> pq = tmap.getOrDefault(id, new PriorityQueue<>(new Comparator<Integer>() {
                @Override
                public int compare(Integer a, Integer b) {
                    return b - a;
                }
            }));
            pq.offer(score);
            tmap.put(id, pq);
        }
        
        int[][] res = new int[tmap.size()][2];
        int i = 0;
        for (Map.Entry<Integer, PriorityQueue<Integer>> entry : tmap.entrySet()) {
            int id = entry.getKey();
            PriorityQueue<Integer> pq = entry.getValue();
            int sum = 0;
            for (int z = 0; z < 5; z++)
                sum += pq.poll();
            res[i][0] = id;
            res[i++][1] = sum / 5;
        }
        
        return res;
    }
}