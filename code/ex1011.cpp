// Binary Search

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int n = weights.size();

        int MAX = INT_MIN, sum = 0;
        for (int i = 0; i < n; i++) {
            MAX = max(MAX, weights[i]);
            sum += weights[i];
        }
        
        int lo = MAX, hi = sum;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            cout<<mid<<" "<<getDays(weights, mid)<<endl;
            if (getDays(weights, mid) <= D) {
                hi = mid - 1;
            }
            else {
                if (getDays(weights, mid + 1) <= D)    return mid + 1;
                else    lo = mid + 1;
            }
        }
        
        return lo;
    }
    
private:
    int getDays(vector<int>& weights, int capacity) {
        int days = 0;
        int sum = 0;
        for (int i = 0; i < weights.size(); i++) {
            sum += weights[i];
            if (sum > capacity) {
                days++;
                sum = weights[i];
            }
        }
        if (sum > 0)    days++;
        return days;
    }
};