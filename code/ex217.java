import java.util.*;
import java.util.concurrent.ThreadLocalRandom;

class Solution {
    // Randomly shuffle the array
    static void shuffleArray(int[] ar)
    {
        // If running on Java 6 or older, use `new Random()` on RHS here
        Random rnd = ThreadLocalRandom.current();
        for (int i = ar.length - 1; i > 0; i--)
        {
            int index = rnd.nextInt(i + 1);
            // Simple swap
            int a = ar[index];
            ar[index] = ar[i];
            ar[i] = a;
        }
    }


    ////////////////////////////////////////////////////////
    // Quick sort functions
    private static void exch(int[] nums, int i, int j) {
        int temp = nums[i];

        nums[i] = nums[j];
        nums[j] = temp;
    }


    private static int partition(int[] nums, int low, int high) {
        int i = low;
        int j = high + 1;

        int v = nums[low];

        while (true) {
            while (nums[++i] < v)
                if (i == high)
                    break;

            while (nums[--j] > v)
                if (j == low)
                    break;

            if (i >= j)
                break;

            exch(nums, i, j);
        }

        exch(nums, low, j);

        return j;
    }


    private static void quickSort(int[] nums, int low, int high) {
        if (high <= low) 
            return;

        int j = partition(nums, low, high);

        // Recursion
        quickSort(nums, low, j - 1);
        quickSort(nums, j + 1, high);
    }


    // Main function
    public boolean containsDuplicate(int[] nums) {

        shuffleArray(nums);
        quickSort(nums, 0, nums.length - 1);

        // for (int i = 0; i < nums.length; i++) {
        //     System.out.print(nums[i]);
        // }

        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] == nums[i + 1])
                return true;
        }

        return false;
    }
}