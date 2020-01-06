class Solution {
    private String source;
    public int shortestWay(String source, String target) {
        // Impossible case
        Set<Character> set = new HashSet<>();
        for (char c : source.toCharArray())    set.add(c);
        for (char c : target.toCharArray())
            if (!set.contains(c))    return -1;
        
        this.source = source;
        int ns = source.length(), nt = target.length();
        int cnt = 0, t = 0, s = 0;
        while (t < nt) {
            while (s < ns && target.charAt(t) != source.charAt(s))
                s++;
            if (s >= ns && t < nt) {
                cnt++;
                s = 0;
                continue;
            }
            t++;    s++;
        }
        return cnt + 1;
    }
}