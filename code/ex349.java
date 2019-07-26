import java.util.*;

class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> set = new HashSet<>();
        
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        
        int p1 = 0, p2 = 0;
        while (p1 < nums1.length && p2 < nums2.length) {
            if (nums1[p1] == nums2[p2])    {set.add(nums1[p1]);    p1++;    p2++;}
            else if (nums1[p1] > nums2[p2])    p2++;
            else if (nums1[p1] < nums2[p2])    p1++;
        }
        
        List<Integer> list = new ArrayList<>(set);
        int[] res = new int[set.size()];
        for (int i = 0; i < set.size(); i++)    res[i] = list.get(i);
    
        return res;
    }
}