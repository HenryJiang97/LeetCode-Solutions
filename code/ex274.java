import java.util.Arrays;

class Solution {
    public int hIndex(int[] citations) {
        // When there is only one citation
        if (citations.length == 0)     return 0;
        
        // First, sort the array
        Arrays.sort(citations);
        
        int h = citations.length;
        int left_bound = 0;
        int right_bound = citations[0];

        
        // When there is only one citation
        if (h == 1)    return (right_bound >= 1) ? 1 : 0;

        // Traverse
        for (int i = 0; i < citations.length; i++) {
            h = citations.length - i;

            if (h >= left_bound && h <= right_bound)    return h;

            left_bound = right_bound;
            if (i + 1 < citations.length)
                right_bound = citations[i + 1];
        }

        return 0;
    }
}