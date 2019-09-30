class Solution {
    public String[] reorderLogFiles(String[] logs) {
        int n = logs.length;

        // Run custom sort
        Arrays.sort(logs, new Comparator<String>() {
            public int compare(String a, String b) {
                String[] loga = a.split(" ");
                String[] logb = b.split(" ");
                boolean aIsLetterlog = Character.isLetter(loga[1].charAt(0));
                boolean bIsLetterlog = Character.isLetter(logb[1].charAt(0));
                
                if (aIsLetterlog && bIsLetterlog) {
                    int cmp = (a.substring(loga[0].length())).compareTo(b.substring(logb[0].length()));
                    if (cmp != 0)    return cmp;
                    else    return (loga[0].compareTo(logb[0]));
                }
                else if (aIsLetterlog ^ bIsLetterlog) {
                    if (aIsLetterlog)    return -1;
                    else    return 1;
                }
                
                return 0;
            }
        });
        
        return logs;
    }
}