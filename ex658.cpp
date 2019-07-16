// Binary search & Two pointers

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        
        // Run binary search to find the index of item close to x
        int lo = 0, hi = n - 1, x_index = -1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            
            if (arr[mid] == x) {
                x_index = mid;
                break;
            } else if (arr[mid] > x)    hi = mid - 1;
            else    lo = mid + 1;
        }
        
        // Get the index of item which is the closest to x
        int index = -1;
        if (x_index != -1)    index = x_index;
        else {
            if (lo < 0 || lo >= n)    index = hi;
            else if (hi < 0 || hi >= n)    index = lo;
            else if (abs(arr[lo] - x) > abs(arr[hi] - x))    index = hi;
            else    index = lo;
        }
        if (index + 1 < n && abs(arr[index + 1] - x) < abs(arr[index] - x))    index++;
        if (index - 1 >= 0 && abs(arr[index - 1] - x) <= abs(arr[index] - x))    index--;
        
        
        // Two pointers to find interval with k elements which is closest to x
        int p1 = index, p2 = index;
        while (p2 - p1 + 1 < k) {
            if (p1 <= 0)    {p2++;    continue;}
            if (p2 >= n - 1)    {p1--;    continue;}
            
            if (abs(arr[p1 - 1] - x) <= abs(arr[p2 + 1] - x))    p1--;
            else if (abs(arr[p2 + 1] - x) < abs(arr[p1 - 1] - x))    p2++;
        }

        
        // Get the result        
        vector<int> res;
        for (int i = p1; i <= p2; i++) {
            res.push_back(arr[i]);
        }
        
        return res;
    }
};