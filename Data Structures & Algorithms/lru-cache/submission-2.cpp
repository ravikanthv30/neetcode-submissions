class LRUCache {
    struct Node {
        int key, val;
        Node *prev, *next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    size_t cap;
    unordered_map<int, Node*> hm;
    Node *head, *tail;               // sentinels: head->next = LRU, tail->prev = MRU

    void unlink(Node* n) {
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }

    void pushBack(Node* n) {         // insert as MRU, just before tail
        n->prev = tail->prev;
        n->next = tail;
        tail->prev->next = n;
        tail->prev = n;
    }

public:
    LRUCache(int capacity) : cap(capacity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache() {
        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }

    LRUCache(const LRUCache&) = delete;
    LRUCache& operator=(const LRUCache&) = delete;

    int get(int key) {
        auto it = hm.find(key);
        if (it == hm.end()) return -1;
        Node* n = it->second;
        unlink(n);
        pushBack(n);
        return n->val;
    }

    void put(int key, int value) {
        auto it = hm.find(key);
        if (it != hm.end()) {              // existing key: update + refresh, no eviction
            Node* n = it->second;
            n->val = value;
            unlink(n);
            pushBack(n);
            return;
        }
        if (hm.size() == cap) {            // new key at capacity: evict LRU
            Node* lru = head->next;
            unlink(lru);
            hm.erase(lru->key);
            delete lru;
        }
        Node* n = new Node(key, value);
        pushBack(n);
        hm[key] = n;
    }
};
/*
// max capacity 
// get and put O(1) 
// duplicate value and duplicate key - udpate value 
// remove the LRU --> O(1)
// hashmap ;  remove and add at O(1) in a specific order =>

class LRUCache {
public:
    unordered_map <int, uint64_t> lru;
    struct ListNode {
        ListNode * next;
        ListNode * prev;
        int key;
        int value;
    };
    ListNode * head;
    ListNode * end;
    int capacity;
    int total;

    ListNode* insert (int key, int value)
    {
        ListNode* newnode = new ListNode;
        if(newnode == NULL)
            return NULL;
        newnode->next=NULL;
        
        newnode->key=key;
        newnode->value=value;
        end.next = newnode;
        newnode->prev=end;
        end = newnode;
        return newnode;
    }
    int remove(void)
    {
        ListNode* newhead = head->next;
        int rmkey = head->key;
        newhead->prev=NULL;
        delete(head);
        head=newhead;
        return rmkey;
    }
    void moveToEnd(ListNode * node)
    {
        if(node)
        {
            if(node==end)
                return;

            ListNode* tmp_next = node->next;
            ListNode* tmp_prev = node->prev;
            if(tmp_next)
                tmp_next->prev = tmp_prev;
            if(tmp_prev)
                tmp_prev->next = tmp_next;

            if(head == node)
                head=tmp_next;
            end.next = node;
            node->prev=end;
            end = node;
        }
        return;
    }

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = nullptr;
        end = nullptr;
        total = 0;
    }
    
    int get(int key) {
        //check for key exists -> if yes remove from list and add it at the end; else return -1
        if(lru.find(key) != lru.end())
        {
            auto it = lru.find(key);
            ListNode* node = it.second;
            int value =  node->value;
            moveToEnd(); 
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        //creat a new list node and add it to hashmap 
        // always add it the end so that head always points to the LRU
        if(total==capacity)
        {
            //remove the lru
            int rmkey = remove();
            lru.remove(rmkey);
            total--;
        }

        if(lru.find(key) == lru.end())
        {
            ListNode* newnode= insert(key, value);
            if(newnode==nullptr)
            {
                //print error
                return;
            }
            lru[key] = newnode;
            total++;
        }
        else
        {
            if(get(key) != value)
            {
                auto it = lru.find(key);
                ListNode* node = it.second;
                node->value = value;
            }
        }
        return;
    }
};
*/