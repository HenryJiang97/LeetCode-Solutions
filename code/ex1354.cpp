class Solution {
public:
    bool isPossible(vector<int>& target) {
        long n = target.size(), sum = 0;
        
        priority_queue<long> pq;
        for (int i = 0; i < n; i++) {
            pq.push(target[i]);
            sum += target[i];
        }
        
        while (1) {
            long cur = pq.top();    pq.pop();
            long restSum = sum - cur;
            if (cur == 1 || restSum == 1)    return 1;
            if (cur - restSum < 1 || restSum == 0 || cur % restSum == 0)    return 0;
            int newVal = cur % restSum;
            pq.push(newVal);
            sum = restSum + newVal;
        }
        
        return 1;
    }
};