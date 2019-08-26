class Solution {
    public int hIndex(int[] citations) {
        int n = citations.length;    if (n == 0)    return 0;
        Arrays.sort(citations);
        
        int h = 1;
        for (int i = n - 1; i >= 1; --i)
        {
            if (citations[i] >= h && citations[i - 1] <= h)
                break;
            
            h++;
        } 
        
        if (h == n && citations[0] < h)    h = 0;
        
        return h;
    }
}