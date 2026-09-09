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
  /*  if(head->next == NULL)
    { 
        Node* h2 = new Node(head->val);
        if(head->random && head->random == head)
            h2->random = h2;
    } */

    unordered_map  <Node*, int> h1_list;
    unordered_map  <int, Node*> h2_list;
    Node* h2 = nullptr;
    Node *h1 = nullptr;
    Node *ret = nullptr;
    h1= head;
    int i=1;
    while(h1)
    {
        Node* dummy=new Node(h1->val);
        if(!dummy)
        {
            cout<<"memory problem!; exit"<< endl;
            return nullptr;
        }
        //fill hash
        h1_list.insert({h1,i});
        h2_list.insert({i,dummy});
        if(!h2)
        {
            h2=dummy;
            ret = h2;
        }
        else
        {
            h2->next = dummy;
            h2 = h2->next;
        }
        h1 = h1->next;
        i++;
    }

    //now find out relataions and fill randoms
    h1=head;
    h2=ret;
    while(h1)
    {
        if(h1->random)
        {
            auto it =  h1_list.find(h1->random);
            auto it2 = h2_list.find(it->second);
           // cout<<"h1 idx:" <<it->second<<"h2:"<<it2->second<<endl;
            h2->random = it2->second;
        }
        h1=h1->next;
        h2=h2->next;
    }
    return ret;     
    }
};
