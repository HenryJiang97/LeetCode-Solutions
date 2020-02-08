class Solution {
    public int n;
    public List<String> findStrobogrammatic(int n) {
        this.n = n;
        return buildString(n);
    }
    
    private List<String> buildString(int remain) {
        if (remain == 0)    return new ArrayList<>(Arrays.asList(""));
        if (remain == 1)    return new ArrayList<>(Arrays.asList("0", "1", "8"));
        
        List<String> res = new ArrayList<>();
        List<String> candidates = buildString(remain - 2);
        for (String s : candidates) {
            if (remain < n)    res.add("0" + s + "0");
            res.add("1" + s + "1");
            res.add("6" + s + "9");
            res.add("8" + s + "8");
            res.add("9" + s + "6");
        }
        return res;
    }
}