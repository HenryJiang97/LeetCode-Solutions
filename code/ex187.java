class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        int n = s.length();
        if (n < 10)    return new ArrayList<>();
        
        List<String> res = new ArrayList<>();
        Set<Integer> visited = new HashSet<>();
        Set<Integer> inRes = new HashSet<>();
        
        int[] map = new int[26];
        map['C' - 'A'] = 1;
        map['G' - 'A'] = 2;
        map['T' - 'A'] = 3;
        
        for (int i = 0; i < n - 9; i++) {
            int code = 0;
            for (int j = i; j < i + 10; j++) {
                code = code << 2;
                code |= map[s.charAt(j) - 'A'];
            }
            if (visited.contains(code) && !inRes.contains(code)) {
                res.add(s.substring(i, i + 10));
                inRes.add(code);
            }
            visited.add(code);
        }
        
        return res;
    }
}