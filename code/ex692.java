// Heap, Hash Map

class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        int n = words.length;
        
        // Add words and frequency to map
        Map<String, Integer> map = new HashMap<>();
        for (String word : words)    map.put(word, map.getOrDefault(word, 0) + 1);
        
        // Define priority queue
        PriorityQueue<String[]> pq = new PriorityQueue<>(new Comparator<String[]>() {
            @Override
            public int compare(String[] a, String[] b) {
                if (!a[1].equals(b[1]))    return Integer.parseInt(b[1]) - Integer.parseInt(a[1]);
                else    return a[0].compareTo(b[0]);
            }
        });
        
        // Offer word, frequency pair to the priority queue
        for (Map.Entry<String, Integer> entry : map.entrySet()) {
            pq.offer(new String[]{entry.getKey(), String.valueOf(entry.getValue())});
        }
        
        // Add first k frequent words to result
        List<String> res = new ArrayList<>();
        for (int i = 0; i < k; i++)    res.add(pq.poll()[0]);
        
        return res;
    }
}