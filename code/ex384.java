import java.util.*;

class Solution {
    int[] original;
    Random rand;
    
    public Solution(int[] nums) {
        original = nums;
        rand = new Random();
    }
    
    /** Resets the array to its original configuration and return it. */
    public int[] reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    public int[] shuffle() {
        int[] shuffle = Arrays.copyOf(original, original.length);
        
        // Swap a random number in array with shuffle[i]
        for (int i = 0; i < shuffle.length; i++) {
            int randomNum = rand.nextInt(shuffle.length);
            if (randomNum != i)    swap(shuffle, i, randomNum);
        }
        
        return shuffle;
    }
    
    // Swap method
    public void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.reset();
 * int[] param_2 = obj.shuffle();
 */