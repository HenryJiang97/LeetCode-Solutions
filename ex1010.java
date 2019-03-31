class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        int res = 0;
        int[] mod = new int[60];
        
        // Build mod array to store the appearence of each mod value
        for (int i = 0; i < time.length; i++) {
            time[i] = time[i] % 60;
            mod[time[i]]++;
        }
        
        // Traverse
        for (int i = 0; i < time.length; i++) {
            mod[time[i]]--;
            res += (time[i] != 0) ? mod[60 - time[i]] : mod[0];
        }
        
        return res;
    }
}