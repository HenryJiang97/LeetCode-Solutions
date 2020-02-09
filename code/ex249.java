class Solution {
    public List<List<String>> groupStrings(String[] strings) {
        List<List<String>> res = new ArrayList<>();
        Map<String, Integer> map = new HashMap<>();
        for (String s : strings)    map.put(s, map.getOrDefault(s, 0) + 1);
        for (String s : strings) {
            if (!map.containsKey(s))    continue;
            List<String> r = new ArrayList<>();
            for (int z = 0; z < map.get(s); z++)    r.add(s);
            map.remove(s);
            for (int i = 1; i < 26; i++) {
                String newS = "";
                for (char c : s.toCharArray()) {
                    newS += (char)((c - 'a' + i) % 26 + 'a');
                }
                if (map.containsKey(newS)) {
                    for (int z = 0; z < map.get(newS); z++)    r.add(newS);
                    map.remove(newS);
                }
            }
            res.add(r);
        }
        return res;
    }
}