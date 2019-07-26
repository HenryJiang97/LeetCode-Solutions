class Solution {
    public static void InsertionSort(char[] ch) {
        for (int i = 1; i < ch.length; i++) {
            // Backup the item going to be inserted
            char backup = ch[i];

            // Find the right position for insertion
            int j;
            for (j = i - 1; j >= 0 && backup < ch[j]; j--) {
                ch[j + 1] = ch[j];
            }

            // Add item to its position
            ch[j + 1] = backup;
        }   
    }
    
    public static char[] sort(String a) {
        char[] ch = a.toCharArray();  

        // Insertion Sort
        InsertionSort(ch);
            
        return ch;
    }

    
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length())
            return false;
        
        char[] ch_s = sort(s);
        char[] ch_t = sort(t);

        // Judge
        for (int i = 0; i < ch_s.length; i++)
            if (ch_s[i] != ch_t[i])
                return false;
        
        return true;
    }
}