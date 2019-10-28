class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        boolean sign = false;    // True : onebit, False : twobits
        
        for (int i = 0; i < bits.length; i++) {
            if (bits[i] == 1) {
                sign = false;
                i++;
            } else {
                sign = true;
            }
        }
        
        return sign;
    }
}