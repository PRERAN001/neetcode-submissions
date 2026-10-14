class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    int cap;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void delnode(Node* node) {
        Node* oldprev = node->prev;
        Node* oldnext = node->next;

        oldprev->next = oldnext;
        oldnext->prev = oldprev;
    }

    void addnode(Node* node) {
        Node* first = head->next;

        head->next = node;
        node->prev = head;

        node->next = first;
        first->prev = node;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        delnode(node);
        addnode(node);

        return node->val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];

            delnode(node);
            mp.erase(key);
            delete node;
        }

        if (mp.size() == cap) {
            Node* lru = tail->prev;

            delnode(lru);
            mp.erase(lru->key);
            delete lru;
        }

        Node* node = new Node(key, value);

        addnode(node);
        mp[key] = node;
    }
};