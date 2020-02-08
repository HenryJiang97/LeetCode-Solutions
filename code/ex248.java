class Solution {
    private int cnt = 0;
    private String low, high;
    
    public int strobogrammaticInRange(String low, String high) {
        this.low = low;    this.high = high;
        String[] dict = new String[]{"0", "1", "a", "b", "c", "d", "9", "e", "8", "6"};
        List<Character> choices = new ArrayList<>(Arrays.asList('0', '1', '6', '8', '9'));
        for (int i = low.length(); i <= high.length(); i++) {
            dfs(choices, dict, i, "", 0);
        }
        return cnt;
    }
    
    private void dfs(List<Character> choices, String[] dict, int n, String cur, int s) {
        if (s == n / 2) {
            if (n % 2 == 1) {
                String s1 = buildString(cur + '0', n, dict);
                String s2 = buildString(cur + '1', n, dict);
                String s3 = buildString(cur + '8', n, dict);
                if (!s1.equals(""))    cnt++;
                if (!s2.equals(""))    cnt++;
                if (!s3.equals(""))    cnt++;
            } else {
                String s4 = buildString(cur, n, dict);
                if (!s4.equals(""))    cnt++;
            }
            return;
        }
        
        for (char c : choices) {
            if (s == 0 && c == '0')    continue;
            dfs(choices, dict, n, cur + c, s + 1);
        }
    }
    
    private String buildString(String s, int n, String[] dict) {
        for (int i = (n + 1) / 2; i < n; i++) {
            s += dict[s.charAt(n - i - 1) - '0'];
        }
        if (s.length() == low.length() && s.compareTo(low) < 0)    return "";
        if (s.length() == high.length() && s.compareTo(high) > 0)    return "";
        return s;
    }
}