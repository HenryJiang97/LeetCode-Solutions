struct DLL {
    int val;
    DLL* next;
    DLL* prev;
    DLL(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class MyCircularDeque {
    int size = 0, capacity;
    DLL* head;
    DLL* tail;
    
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        this->capacity = k;
        this->head = new DLL(0);
        this->tail = new DLL(0);
        head->next = tail;
        tail->prev = head;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull())    return 0;
        
        // Insert the new node to the front of double linked list
        DLL* node = new DLL(value);
        node->next = head->next;
        node->prev = node->next->prev;
        head->next = node;
        node->next->prev = node;
        
        size++;
        return 1;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull())    return 0;
        
        // Insert the new node to the tail of double linked list
        DLL* node = new DLL(value);
        node->next = tail;
        node->prev = tail->prev;
        node->prev->next = node;
        tail->prev = node;
        
        size++;
        return 1;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty())    return 0;
        
        // Delete node from the front of the linked list
        DLL* node = head->next;
        head->next = node->next;
        node->next->prev = head;
        
        size--;
        return 1;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty())    return 0;
        
        // Delete node from the tail of the linked list
        DLL* node = tail->prev;
        node->prev->next = tail;
        tail->prev = node->prev;
        
        size--;
        return 1;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        return isEmpty() ? -1 : head->next->val;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        return isEmpty() ? -1 : tail->prev->val;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size >= capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */