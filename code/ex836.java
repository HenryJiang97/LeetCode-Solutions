class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        int xlo1 = rec1[0], xhi1 = rec1[2], ylo1 = rec1[1], yhi1 = rec1[3];
        int xlo2 = rec2[0], xhi2 = rec2[2], ylo2 = rec2[1], yhi2 = rec2[3];
        
        boolean x = false, y = false;
        if (xlo2 < xhi1 && xlo2 >= xlo1 || xlo1 < xhi2 && xlo1 >= xlo2)
            x = true;
        
        if (ylo2 < yhi1 && ylo2 >= ylo1 || ylo1 < yhi2 && ylo1 >= ylo2)
            y = true;
            
        return x && y;
    }
}