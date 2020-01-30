class Solution {
    public Map<String, Integer> memo = new HashMap<>();
    
    public int longestDecomposition(String text) {
        if (memo.containsKey(text))    return memo.get(text);
        int n = text.length();
        if (n == 0)    return 0;
        if (n == 1)    return 1;
        int cnt = 1;
        for (int p = 0; p <= n / 2 - 1; p++) {
            String front = text.substring(0, p + 1);
            if (text.startsWith(front, n - front.length())) {    // Found match
                String middle = text.substring(p + 1, n - front.length());
                cnt = Math.max(cnt, longestDecomposition(middle) + 2);
            }
        }
        memo.put(text, cnt);
        return cnt;
    }
}