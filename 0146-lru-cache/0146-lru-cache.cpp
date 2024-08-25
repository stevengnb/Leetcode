class LRUCache {
struct Node {
    int key;
    int val;
    Node *next;
    Node *prev;
    Node(int val, int key) : val(val), key(key), next(nullptr), prev(nullptr) {}
};

public:
    unordered_map<int, Node*> map;
    Node *head = nullptr;
    Node *tail = nullptr;
    int max;

    LRUCache(int capacity) {
        max = capacity;
    }
    
    int get(int key) {
        if(map.find(key) == map.end()) return -1;
        
        Node *updateNode = map[key];
        update(updateNode, updateNode->val);

        return updateNode->val;
    }

    void update(Node *updateNode, int value) {
        Node *newNode = new Node(value, updateNode->key);

        if(head == tail) {
            head = tail = newNode;
        } else if(head == updateNode) {
            head = head->next;
        } else if(tail == updateNode) {
            tail = tail->prev;
        } 
        
        if(updateNode->prev) updateNode->prev->next = updateNode->next;
        if(updateNode->next) updateNode->next->prev = updateNode->prev;
        updateNode = nullptr;

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;

        map[newNode->key] = newNode;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()) {
            update(map[key], value);
        } else {
            Node *newNode = new Node(value, key);

            if(map.size() >= max) {
                map.erase(head->key);
                head = head->next;
            } 

            if(!head) {
                head = tail = newNode;
            } else if(head == tail) {
                head->next = newNode;
                newNode->prev = head;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            map[key] = newNode;
        }
    }
};