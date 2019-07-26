// Boundary count

class MyCalendarThree {
    map<int, int> m;
    
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        m[start]++;    m[end]--;
        
        int k = 0, MAX = 0;
        for (auto entry : m) {
            k += entry.second;
            MAX = max(MAX, k);
        }
        
        return MAX;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */