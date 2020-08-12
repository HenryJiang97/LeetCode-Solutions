class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> arr{1};
        for (int i = 1; i <= rowIndex; i++)
            getNext(arr);
        return arr;
    }
    
private:
    void getNext(vector<int>& arr) {
        int n = arr.size();
        for (int i = n - 1; i > 0; i--)
            arr[i] = arr[i] + arr[i - 1];
        arr.push_back(1);
    }
};