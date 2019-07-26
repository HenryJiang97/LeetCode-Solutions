class Solution {
    public int lastRemaining(int n) {
        int head = 1;
        boolean fromLeft = true;
        int remaining = n;
        int gap = 1;
        
        while (remaining > 1) {
            // If start from left or the from right but the remaining number is odd,
            // Move head to the next gap position
            if (fromLeft || remaining % 2 == 1)
                head += gap;
            
            // Update gap, remaining and the state of fromLeft
            gap *= 2;
            remaining /= 2;
            fromLeft = !fromLeft;
        }
        
        return head;
    }
}