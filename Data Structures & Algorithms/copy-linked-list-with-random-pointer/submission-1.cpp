/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
    //is it like the intention is to replicate the relation of the nodes in a new list.
    //can there be duplicates ? if not, i can find the link by unique number --> yes duplicates are allowed.
    //so I need to make a new list and fine the next of the node and find the same/similar node in new list and fill hte random.   o(n2) where running 2 loops for each node to find out.
    // use hash table for example - store value pair -  how to handle duplicates ? -
    //index is the main need here -> random = which node in the list ? how to find index -> pointer and index (hasmap) 
    //1 - p1 ; 2 - p2 ; 3 - p3; 4 = p4
    //getidnex(7->random p4) => 4 ; 4 -> pointer new one
    //o(n*4) ; o(2n) 
//actual list -> random --> get hash index 

    //edge cases - null return, head->next null -> copy same

    if(!head)
        return nullptr;

    unordered_map  <Node*, Node*> hlist;
    Node* h = head;
    Node *ret = nullptr;
    hlist[NULL] = NULL;

    while(h)
    {
        Node* dummy=new Node(h->val);
        if(!dummy)
        {
            cout<<"memory problem!; exit"<< endl;
            return nullptr;
            //free up things here
        }
        //fill hash
        hlist[h] = dummy;
        h=h->next;
    }

    //now find out relataions and fill randoms
    h=head;
    while(h)
    {
       Node *h2 = hlist[h];
       h2->val = h->val;
       h2->random = hlist[h->random];
       h2->next = hlist[h->next];
       h= h->next;
    }
    return hlist[head];
    }
};
