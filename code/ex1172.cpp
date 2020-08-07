class DinnerPlates {
    int cap;
    map<int, vector<int>> stacks;
    set<int> vacant;
public:
    DinnerPlates(int capacity) {
        cap = capacity;
    }
    
    void push(int val) {
        if (vacant.empty())
            vacant.insert(stacks.size());
        stacks[*vacant.begin()].push_back(val);
        if (stacks[*vacant.begin()].size() >= cap)
            vacant.erase(*vacant.begin());
    }
    
    int pop() {
        while (!stacks.empty() && (*stacks.rbegin()).second.empty()) {
            if (vacant.count((*stacks.rbegin()).first) > 0)
                vacant.erase((*stacks.rbegin()).first);
            stacks.erase((*stacks.rbegin()).first);
        }
        if (stacks.empty())    return -1;
        int val = (*stacks.rbegin()).second.back();
        (*stacks.rbegin()).second.pop_back();
        return val;
    }
    
    int popAtStack(int index) {
        if (stacks.count(index) == 0 || stacks[index].empty())
            return -1;
        int val = stacks[index].back();
        stacks[index].pop_back();
        vacant.insert(index);
        return val;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */