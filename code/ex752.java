
// BFS

class Solution {
    public int openLock(String[] deadends, String target) {
        Set<String> lock = new HashSet<>();
        for (String deadend : deadends)    lock.add(deadend);
        
        Queue<String> queue = new LinkedList<>();
        Set<String> visited = new HashSet<>();
        queue.offer("0000");    if (target.equals("0000"))    return 0;     
        if (lock.contains("0000"))    return -1;
        visited.add("0000");
        
        int step = 0;
        while (!queue.isEmpty()) {
            for (int z = queue.size(); z > 0; --z) {
                String out = queue.poll();
                
                // Try to turn each wheel two directions
                for (int i = 0; i < 4; i++) {
                    // Turn each wheel forward
                    StringBuilder sb = new StringBuilder(out);
                    sb.setCharAt(i, (char)((sb.charAt(i) - '0' + 1) % 10 + '0'));
                    String newStr = sb.toString();
                    if (newStr.equals(target))    return step + 1;
                    if (!visited.contains(newStr) && !lock.contains(newStr)) {
                        queue.offer(newStr);
                        visited.add(newStr);
                    }
                    
                    // Turn each wheel backward
                    sb = new StringBuilder(out);
                    sb.setCharAt(i, (char)((sb.charAt(i) - '0' + 9) % 10 + '0'));
                    newStr = sb.toString();
                    if (newStr.equals(target))    return step + 1;
                    if (!visited.contains(newStr) && !lock.contains(newStr)) {
                        queue.offer(newStr);
                        visited.add(newStr);
                    }
                }
            }
            step++;
        }
        
        return -1;
    }
}