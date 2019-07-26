// Heap

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        // Classify and get the info of these barcode
        unordered_map<int, int> map;
        for (auto barcode : barcodes) {
            if (map.find(barcode) != map.end())
                map[barcode]++;
            else
                map[barcode] = 1;
        }
        
        priority_queue<pair<int, int>> pq;
        for (auto itr : map)
            pq.push(make_pair(itr.second, itr.first));
        
        vector<int> res;        
        while (!pq.empty()) {
            if (pq.size() >= 2) {
                vector<pair<int, int>> temp;
                
                // Add top two items in the queue to the result
                res.push_back(pq.top().second);
                temp.push_back(pq.top());
                pq.pop();
                
                res.push_back(pq.top().second);
                temp.push_back(pq.top());
                pq.pop();
                
                // Add items in temp back to the queue
                for (auto p : temp) {
                    p.first -= 1;
                    if (p.first != 0)    pq.push(p);
                }
            } else if (pq.size() == 1) {
                if (pq.top().first > 1 || (res.size() > 0 && pq.top().second == res[res.size() - 1]))    return {};
                else {
                    res.push_back(pq.top().second);
                    pq.pop();
                }
            }
        }
        
        return res;
    }
};