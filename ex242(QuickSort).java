import java.util.*;
import java.util.concurrent.ThreadLocalRandom;

class Solution {
    // Randomly shuffle the array
    private static void shuffleArray(char[] ar)
    {
        // If running on Java 6 or older, use `new Random()` on RHS here
        Random rnd = ThreadLocalRandom.current();
        for (int i = ar.length - 1; i > 0; i--)
        {
            int index = rnd.nextInt(i + 1);
            // Simple swap
            char a = ar[index];
            ar[index] = ar[i];
            ar[i] = a;
        }
    }


    ////////////////////////////////////////////////////////
    // Quick sort functions
    private static void exch(char[] nums, int i, int j) {
        char temp = nums[i];

        nums[i] = nums[j];
        nums[j] = temp;
    }


    private static int partition(char[] nums, int low, int high) {
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


    private static void quickSort(char[] nums, int low, int high) {
        if (high <= low) 
            return;

        // Do a partition to seperate the array into two parts
        int j = partition(nums, low, high);

        // Recursion
        quickSort(nums, low, j - 1);
        quickSort(nums, j + 1, high);
    }



 //////////////////////////////////////////////////
    // Main
    public static char[] sort(String a) {
        char[] ch = a.toCharArray();  

        // Quick Sort
        shuffleArray(ch);
        quickSort(ch, 0, ch.length - 1);
            
        return ch;
    }

    
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length())
            return false;
        
        char[] ch_s = sort(s);
        char[] ch_t = sort(t);

        
        // Judge
        for (int i = 0; i < ch_s.length; i++)
            if (ch_s[i] != ch_t[i])
                return false;
        
        return true;
    }
}