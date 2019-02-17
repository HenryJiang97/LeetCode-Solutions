import java.util.List;
import java.util.ArrayList;

class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> r = new ArrayList<>();
        
        String string = "";
        int count = 0;
        int space = 0;
        int space_total = 0;
        int i = 0;
        int start = 0;

        while (i < words.length) {
            count = count + words[i].length();
            i++;
            
            // Got the items for a line
            if (count + (i - start - 1)  > maxWidth) {
                i -= 1;              
                
                // Get the total spaces in this line
                count -= words[i].length();
                space_total = maxWidth - count;
                
                // Form up the line with words and spaces
                for (int j = start; j < i; j++) {        
                    string += words[j];    // Add words

                    if (j < i - 1) {
                        // Count the space needed between two words
                        space = (space_total % (i - j - 1) == 0) ? space_total / (i - j - 1) : space_total / (i - j - 1) + 1;

                        
                        if (space_total >= space)
                            for (int z = 0; z < space; z++)    string += " ";
                        else
                            for (int z = 0; z < space_total; z++)   string += " ";
                        
                    
                        space_total -= space;
                    } else
                        // Add spaces at the end of the line if applicable
                        for (int z = 0; z < space_total; z++)   string += " ";   
                }

                r.add(string);    // Add this line to the array list
                
                // Re-init variables
                string = "";
                count = 0;
                start = i;
            }
        }
        
        // Add the last line to the list
        for (int j = start; j < words.length; j++) {
            string = string + words[j];
            if (string.length() < maxWidth)    string += " ";
        }
    
        // Add last few spaces to the end of the last line
        int len = string.length();
        for (int z = 0; z < maxWidth - len; z++)    string += " ";
        r.add(string);
        
       
        return r;
    }
}