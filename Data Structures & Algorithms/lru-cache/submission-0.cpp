//get and put needs to be O(1) so we have to use hash map 
// keep track of the operations -> is there a limit ?
//MRU is not there LRU ; 1 oper
//300 --> operation --> queue --> [2 - 1] Linked list --> end and start 
//  front [1 <-> 4 <-> 2] tail ==> find move around and remove from end  
// hash key - address --> [key, value]
// move node to front 

class ListNode {
public:
    int key;
    int val;
    ListNode* next;
    ListNode* prev;

    ListNode(int init_key, int init_val)
    {
        key = init_key;
        val = init_val;
        next = nullptr;
        prev = nullptr;
    };
};

class LRUCache {

    unordered_map <int,ListNode*> hm;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    int cap = 0;

    void removeatList(ListNode * node)
    {
        ListNode* next = node->next;
        ListNode* prev = node->prev;
        prev->next = node->next;
        next->prev = node->prev;
    }

    void insertatEnd(ListNode * node)
    {
        ListNode * tmp = tail->prev;
        tmp->next = node;
        tail->prev = node;
        node->next = tail;
        node->prev = tmp;
    }


public:
    LRUCache(int capacity) {
        cap = capacity;
        //create a dll of capacity 
        head = new ListNode(0,0);
        tail = new ListNode(0,0);
        head->next = tail;
        tail->prev = head;
        //create a hashmap of this
        hm.clear();
    }
    
    int get(int key) {
        //get hashmap of key and return
        auto it = hm.find(key);
        if( it != hm.end())
        {
            ListNode* addr = it->second;   
            removeatList(addr);
            insertatEnd(addr);
            return addr->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        /*get key -> if Yes -> check value --> if good return trye
                                            --> if no update value
                --> if no --> add value key pair
        */
        auto it = hm.find(key);
        if( it != hm.end())
        {
            ListNode* addr1 = it->second;
            removeatList(addr1);
            hm.erase(addr1->key);
            delete(addr1);
        }
        cout <<"size" << hm.size() << "cap" << cap <<endl;
        if(hm.size() > cap-1)
        {
            ListNode * addr = head->next;
            hm.erase(addr->key);
            removeatList(addr);
            delete(addr);
        }

        ListNode* addr = new ListNode(key, value);
        insertatEnd(addr);
        hm.insert({key, addr});


    }
};
