class Solution {
    public int lengthLongestPath(String input) {
        int res = 0;
        String[] str = input.split("\n");
        int[] level_length = new int[str.length];
        
        for (String s : str) {
            int last_tab = s.lastIndexOf('\t');
            int level = last_tab + 1;
            int current_len = s.length() - last_tab - 1;
            int parent_len = (level == 0) ? 0 : level_length[level - 1] + 1;
            int total_len = current_len + parent_len;
            level_length[level] = total_len;
            
            if (s.contains("."))
                res = Math.max(res, total_len);
        }
        
        return res;
    }
}