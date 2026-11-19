//Node class with all needed variables 
// head and tail pointers to maintain that
// hasmap for key, node poitner
// cap, count 
// helper functions -> insertAtEnd and removeNode

//put 1, 10 

class Node {
public:
    int key;
    int value;
    Node* next;
    Node* prev;

    Node(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {};
};

class LRUCache {
public:
    unordered_map <int, Node*> lru;
    Node* head;
    Node* tail;
    int cap;
    int count;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        count = 0;
        lru.clear();
    }
    
    void remove(Node* node)
    {
        Node* tmp_next = node->next;
        Node* tmp_prev = node->prev;

        tmp_prev->next = tmp_next;
        tmp_next->prev = tmp_prev;
        return;
        
    }
    void insertAtEnd(Node* node)
    {
        Node* tmp_prev = tail->prev;
        
        node->next = tail;
        node->prev = tmp_prev;
        tail->prev = node;
        tmp_prev->next = node;
        return;
    }
    int get(int key) {
//get - find key, move node to end and return, if not -1, 
        auto it = lru.find(key);
        if(it == lru.end())
            return -1;
        Node* node = it->second;
        if(count > 1)  //optimization to avoid remove and insert operations
        {
            remove(node);
            insertAtEnd(node);
        }
        return node->value;
    }
    
    void put(int key, int value) {
//put - if(key exists) -> update value ; 
// if not (check cap hit ) - yes - remove LRU
// insert new into hashmap and list 
        auto it = lru.find(key);
        if(it != lru.end())
        {
            if(get(key) != value)
                (it->second)->value = value;
            return;
        }
        if(count >= cap)
        {
            Node* tmp = head->next;
            remove(tmp);
            lru.erase(tmp->key);
            delete(tmp);
            count --;
        }
        Node *newnode = new Node(key, value);
        insertAtEnd(newnode);
        lru[key]= newnode;
        count++;

        return;
    }
};
