// BFS

class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String> dict = new HashSet<>(wordList);
        if (!dict.contains(endWord))    return 0;
        
        int layer = 0;
        Queue<String> queue = new LinkedList<>();
        queue.offer(beginWord);    layer++;
        
        while (!queue.isEmpty()) {
            int queue_size = queue.size();

            for (int q = 0; q < queue_size; ++q) {    // Loop through a layer
                String out = queue.poll();
            
                for (int i = 0; i < out.length(); i++) {    // Loop through each digits
                    
                    for (char c = 'a'; c <= 'z'; c++) {    // Loop each char 'a'-'z' to replace that digit
                        String newstring = out.substring(0, i) + c + out.substring(i + 1);
                        if (!dict.contains(newstring))    continue;
                        
                        if (newstring.equals(endWord))    return layer + 1;
                        else {
                            queue.offer(newstring);
                            dict.remove(newstring);
                        }
                    }
                }
            }
            layer++;
        }

        return 0;
    }
}