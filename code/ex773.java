class Solution {
    public int slidingPuzzle(int[][] board) {    
        String ans = "123450";
        // BFS
        Queue<String> queue = new LinkedList<>();
        Set<String> set = new HashSet<>();
        String init = boardToString(board);    if (init.equals(ans))    return 0;
        queue.offer(init);
        set.add(init);
        int step = 0;
        
        while (!queue.isEmpty()) {
            for (int z = queue.size(); z > 0; --z) {
                String out = queue.poll();
                int i = 0;
                for (i = 0; i < 6; i++)    if (out.charAt(i) == '0')    break;
                
                // Move squares from four directions to this blank space
                // Move up square
                if (i - 3 >= 0) {
                    StringBuilder sb = new StringBuilder(out);
                    sb.setCharAt(i, sb.charAt(i - 3));
                    sb.setCharAt(i - 3, '0');
                    String newstr = sb.toString();
                    if (newstr.equals(ans))    return step + 1;
                    if (!set.contains(newstr)) {
                        queue.offer(newstr);
                        set.add(newstr);
                    }
                }
                // Move down square
                if (i + 3 < 6) {
                    StringBuilder sb = new StringBuilder(out);
                    sb.setCharAt(i, sb.charAt(i + 3));
                    sb.setCharAt(i + 3, '0');
                    String newstr = sb.toString();
                    if (newstr.equals(ans))    return step + 1;
                    if (!set.contains(newstr)) {
                        queue.offer(newstr);
                        set.add(newstr);
                    }
                }
                // Move left square
                if (i % 3 - 1 >= 0) {
                    StringBuilder sb = new StringBuilder(out);
                    sb.setCharAt(i, sb.charAt(i - 1));
                    sb.setCharAt(i - 1, '0');
                    String newstr = sb.toString();
                    if (newstr.equals(ans))    return step + 1;
                    if (!set.contains(newstr)) {
                        queue.offer(newstr);
                        set.add(newstr);
                    }
                }
                // Move up square
                if (i % 3 + 1 < 3) {
                    StringBuilder sb = new StringBuilder(out);
                    sb.setCharAt(i, sb.charAt(i + 1));
                    sb.setCharAt(i + 1, '0');
                    String newstr = sb.toString();
                    if (newstr.equals(ans))    return step + 1;
                    if (!set.contains(newstr)) {
                        queue.offer(newstr);
                        set.add(newstr);
                    }
                }
            }
            step++;
        }
        
        return -1;
    }
    
    private String boardToString(int[][] board) {
        String s = "";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                s += String.valueOf(board[i][j]);
            }
        }
        return s;
    }
}