class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        int n = arr.length;
        
        // Find the index of element in arr which is closest to x
        int idx = 0;
        if (x <= arr[0])    idx = 0;
        else if (x >= arr[n - 1])    idx = n - 1;
        else {
            int lo = 0, hi = n - 1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (arr[mid] == x) {
                    idx = mid;
                    break;
                } else if (arr[mid] < x) {
                    if (arr[mid + 1] >= x) {
                        idx = arr[mid + 1] - x < x - arr[mid] ? mid + 1 : mid;
                        break;
                    }
                    lo = mid + 1;
                } else {
                    if (arr[mid - 1] <= x) {
                        idx = arr[mid] - x < x - arr[mid - 1] ? mid : mid - 1;
                        break;
                    }
                    hi = mid - 1;
                }
            }
        }
        
        // Use two pointers to find k closest elements to x
        int l = idx, r = idx;
        while (r - l + 1 < k) {
            if (l <= 0)    {r++;    continue;}
            if (r >= n - 1)    {l--;    continue;}
            if (x - arr[l - 1] <= arr[r + 1] - x)    l--;
            else    r++;
        }
        
        // Get result
        List<Integer> res = new ArrayList<>();
        for (int i = l; i <= r; i++)
            res.add(arr[i]);
        
        return res;
    }
}