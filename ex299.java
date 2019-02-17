import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
    public String getHint(String secret, String guess) {
        int a = 0, b = 0;
        List<Character> list_s = new ArrayList<>();
        List<Character> list_g = new ArrayList<>();
        
        // Traverse two strings
        for (int i = 0; i < secret.length(); i++) {
            if (secret.charAt(i) == guess.charAt(i))
                a++;
            else {
                list_s.add(secret.charAt(i));
                list_g.add(guess.charAt(i));
            }
        }

        // Sort two lists, make them sorted in ascending order
        Collections.sort(list_s);
        Collections.sort(list_g);

        
        // Traverse two lists and check how many digits are same
        int i = 0, j = 0;

        while (i < list_s.size() && j < list_g.size()) {
            if (list_s.get(i) == list_g.get(j)) {
                b++;    i++;    j++;
            } else if (list_s.get(i) > list_g.get(j))
                j++;
            else
                i++;
        }

        
        return Integer.toString(a) + "A" + Integer.toString(b) + "B";
    }
}