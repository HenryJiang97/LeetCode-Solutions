// Hashmap, Double Linked List

class LRUCache {
    struct DBLinkedList {    // Define double linked list data structure
        int key;
        int val;
        DBLinkedList* prev = NULL;
        DBLinkedList* next = NULL;
        DBLinkedList(int key, int val) {    // Init
            this->key = key;
            this->val = val;
        }
    }; 
    
    unordered_map<int, DBLinkedList*> dict;    // Hashmap to store the key-value pair
    int capacity, cap;
    DBLinkedList* head = new DBLinkedList(0, 0);
    DBLinkedList* end = new DBLinkedList(0, 0);
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        cap = 0;
        
        // Init the double linked list
        head->next = end;    end->prev = head;
    }
    
    int get(int key) {
        if (dict.find(key) == dict.end())    return -1;
        
        auto node = dict[key];
        int value = node->val;
        
        remove(dict[key]);    add(node);    
        dict[key] = node;
        
        return value;
    }
    
    void put(int key, int value) {
        if (dict.find(key) == dict.end()) {    // New node
            if (cap >= capacity) {    // Remove the last item
                dict.erase(end->prev->key);
                remove(end->prev);
                cap--;
            }

            DBLinkedList* newNode = new DBLinkedList(key, value);
            add(newNode);    cap++;
            dict[key] = newNode;    // Update map
            
        } else {    // Existed node
            auto existedNode = dict[key];
            remove(dict[key]);
            
            existedNode->val = value;
            add(existedNode);
            dict[key] = existedNode;    // Update map
        }
    }
    
    //////////////////////////////////////////////////////////////////////////////////
    void remove(DBLinkedList* node) {    // Remove a node from the double linked list
        auto prevNode = node->prev;
        auto nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    
    void add(DBLinkedList* node) {    // Add a node to the front of the double linked list
        node->next = head->next;
        head->next = node;
        node->next->prev = node;
        node->prev = head;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */