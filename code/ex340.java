// Sliding window

class Solution {
    public int lengthOfLongestSubstringKDistinct(String s, int K) {
        int n = s.length();    if (n == 0 || K == 0)    return 0;
        char[] c = s.toCharArray();
        
        Map<Character, Integer> cnt = new HashMap<>();
        cnt.put(c[0], 1);
        
        int max = 1;
        int left = 0, right = 1, k = 1;
        while (right < n) {
            // Move right pointer to right
            // Update cnt map
            if (!cnt.containsKey(c[right])) {
                k++;
                cnt.put(c[right], 1);
            } else {
                cnt.put(c[right], cnt.get(c[right]) + 1);
            }

            if (k <= K)    max = Math.max(max, right - left + 1);
            
            // Move left pointer to right to make T having at most K distince characters
            while (left <= right && k > K) {
                if (cnt.get(c[left]) - 1 == 0) {
                    cnt.remove(c[left]);
                    k--;
                } else {
                    cnt.put(c[left], cnt.get(c[left]) - 1);
                }
                left++;
            }
            
            if (k <= K)    max = Math.max(max, right - left + 1);
            
            right++;
        }
        
        return max;
    }
}