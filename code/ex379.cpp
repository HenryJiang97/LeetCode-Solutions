class PhoneDirectory {
    int n;
    queue<int> que;
    unordered_set<int> set;
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        n = maxNumbers;
        for (int i = 0; i < maxNumbers; i++)
            que.push(i);
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (que.empty()) {
            return -1;
        } else {
            int ret = que.front();
            que.pop();
            set.insert(ret);
            return ret;
        }
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return set.find(number) == set.end();
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (number >= n || set.find(number) == set.end())    return;
        que.push(number);
        set.erase(number);
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */