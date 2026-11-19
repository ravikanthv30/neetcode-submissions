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
    void reorderList(ListNode* head) {
        //specific order -> 0 first node as is, 2nd node would be last one , 3rd would be 2nd earlier , 4th would be n-2
        //we can start 2 pointers --> l and r
        // l --> r --> l --> r for each loop and move ahead the l++ and r-- 
        //but this is a single linked list i can have one coming from back 
        // so use stack to push all the nodes and pop up them till you meet in mid way 
        //step1: build a stack for full list 
        //step2 : start from 1 and every next node get it from stack
        // step3: if we meet - break and set NULL for end and free nodes in stack 
        stack  <ListNode*>st;
        ListNode* l = head;
        ListNode* r = head;
        while(r)
        {
          st.push(r);
          r=r->next;
        }
        int len = st.size()/2;
        int i =0;
       for (int i = 0; i < len; i++)
        {
            ListNode* temp = l->next;
            ListNode* topNode = st.top();
            st.pop();

            l->next = topNode;
            topNode->next = temp;
            l = temp;
        }
        l->next = NULL;
    }
};
