class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        int n = words.length;
        List<String> res = new ArrayList<>();
        
        for (int i = 0, l, k; i < n; i += k) {
            // Get the max number of words can be put in current line
            for (l = k = 0; i + k < n && l + k + words[i + k].length() <= maxWidth; k++) {
                l += words[i + k].length();
            }
            
            // Build current line
            String line = words[i];
            for (int j = 1; j < k; j++) {
                if (i + k >= n) {    // The last line
                    line += " ";                    
                } else {
                    int spaces = (maxWidth - l) / (k - 1) + ((j <= (maxWidth - l) % (k - 1)) ? 1 : 0);
                    line += multipleSpaces(spaces);
                }
                line += words[i + j];
            }
            int restSpaces = maxWidth - line.length();
            line += multipleSpaces(restSpaces);
            res.add(line);
        }
        
        return res;
    }
    
    private String multipleSpaces(int n) {
        String ret = "";
        for (int i = 0; i < n; i++)
            ret += " ";
        return ret;
    }
}