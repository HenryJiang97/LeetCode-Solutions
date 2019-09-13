class Solution {
    public String mostCommonWord(String paragraph, String[] banned) {
        Set<String> ban = new HashSet<>();
        for (String b : banned)    ban.add(b);
        
        // Save words to a map
        Map<String, Integer> map = new HashMap<>();
        String s = "";
        int p = 0;
        while (p < paragraph.length()) {
            char c = paragraph.charAt(p);
            if (Character.isLetter(c)) {
                s += Character.toString(Character.toLowerCase(c));
            } else {
                if (s.length() > 0)    map.put(s, map.getOrDefault(s, 0) + 1);
                s = "";
            }
            p++;
        }
        if (s.length() > 0)    map.put(s, map.getOrDefault(s, 0) + 1);
        System.out.println(map);
        
        // Get result
        String res = "";
        int max = 0;
        for (Map.Entry<String, Integer> entry : map.entrySet()) {
            String str = entry.getKey();
            if (entry.getValue() > max && !ban.contains(str)) {
                res = str;
                max = entry.getValue();
            }
        }
        
        return res;
    }
}