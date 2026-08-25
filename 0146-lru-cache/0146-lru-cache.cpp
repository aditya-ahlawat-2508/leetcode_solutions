class LRUCache {
private:
    // Doubly linked list node
    class Node {
    public:
        int key, value;
        Node* next;
        Node* prev;
        Node(int k, int v) {
            key = k;
            value = v;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* head;   // dummy head
    Node* tail;   // dummy tail
    int capacity;
    unordered_map<int, Node*> mp;  // key -> node reference

    // Delete a given node from wherever it is in the list (O(1))
    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Insert a given node right after the dummy head (marks it as most recently used)
    void insertAfterHead(Node* node) {
        Node* currAfterHead = head->next;
        head->next = node;
        node->prev = head;
        node->next = currAfterHead;
        currAfterHead->prev = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        mp.clear();
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;   // not present
        }
        Node* node = mp[key];
        int val = node->value;

        // mark as most recently used
        deleteNode(node);
        insertAfterHead(node);

        return val;
    }

    void put(int key, int value) {
        // Case 1: key already exists -> update value, move to front
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;
            deleteNode(node);
            insertAfterHead(node);
            return;
        }

        // Case 2: key doesn't exist, cache is full -> evict LRU (tail->prev)
        if (mp.size() == capacity) {
            Node* lruNode = tail->prev;
            mp.erase(lruNode->key);
            deleteNode(lruNode);
            delete lruNode;   // free memory
        }

        // Case 3: insert new node
        Node* newNode = new Node(key, value);
        mp[key] = newNode;
        insertAfterHead(newNode);
    }
};