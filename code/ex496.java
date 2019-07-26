class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int n1 = nums1.length, n2 = nums2.length;
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = n2 - 1; i >= 0; --i) {
            for (int j = i + 1; j < n2; ++j) {
                if (nums2[j] > nums2[i]) {
                    map.put(nums2[i], nums2[j]);
                    break;
                }
            }
        }
        
        int[] res = new int[n1];
        for (int i = 0; i < n1; i++)
            res[i] = map.getOrDefault(nums1[i], -1);
        
        return res;
    }
}