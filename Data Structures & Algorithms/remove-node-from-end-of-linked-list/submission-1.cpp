/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //run a pointer till n and then start another S pointer; go till end S will land Last -n
        //corner cases -> no list or list has only 1 with n=1  return NULL
        //if n=list len then it can be head -> then replace head and return that 
        //if n> list_len ==> do i need to handle this case ? if so, return NULL or -1 ?
        if( !head || (head->next==NULL && n==1))
            return NULL;
        if(n==0)
            return head;
//1 2 ; n =2
// del-> N - N - 1 
//prev-> N - N - N
// i ->  1 - 2 - 3
// it -> 1 - 2 - N
        ListNode *it = head;
        ListNode *delNode = NULL;
        ListNode *prevNode = NULL;
        int i=1;
        while(it)
        {
            if(i==n)
                delNode=head;
            else if(i>n)
            {
                prevNode = delNode;
                delNode=delNode->next;
            }
            it = it->next;
            i++;
        }
        //delnode is at N+1 from last, lets delete that
        if(delNode==NULL)
            //this means N > legth 
            return NULL;
        ListNode* temp = delNode->next;
        if(prevNode)
        {
            prevNode->next = temp;
        }
        else 
            head = delNode->next;
        delete(delNode);
        return head;
    }
};



