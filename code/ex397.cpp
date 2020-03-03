class Solution {
public:
    int integerReplacement(int n) {
        queue<long> que;
        unordered_set<long> visited;
        que.push(n);
        visited.insert(n);
        int step = 0;
        while (!que.empty()) {
            int size = que.size();
            for (int z = size; z > 0; z--) {
                long out = que.front();    que.pop();
                if (out == 1)    return step;
                if (out % 2 == 0) {
                    if (visited.find(out / 2) == visited.end()) {
                        visited.insert(out / 2);
                        que.push(out / 2);
                    }
                } else {
                    if (out - 1 > 0 && visited.find(out - 1) == visited.end()) {
                        visited.insert(out - 1);
                        que.push(out - 1);
                    }
                    if (visited.find(out + 1) == visited.end()) {
                        visited.insert(out + 1);
                        que.push(out + 1);
                    }
                }
            }
            step++;
        }
        return 0;
    }
};