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

//k - 0-n ;  n-> anything 
// reverse the list --> call for each K length ; head needs to be modifed 
// go from start to k --> curr->next =  revList(start, end) 
// if null --> return head;
//edgecase: -> Null -> return null

class Solution {
public:


ListNode* revList(ListNode* start,ListNode* end)
{
    ListNode* curr = start;
    ListNode* next = start;
    ListNode* prev = nullptr;
    while(curr != end)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode *dummy = new ListNode(0, head);
        ListNode *curr = dummy;

        while(curr && curr->next)
        {
            ListNode* start = curr->next;
            ListNode* end = curr;
            for(int i=0; i<k; i++)
            {
                if(end->next)
                    end = end->next;
                else 
                    return dummy->next;
            }

            ListNode * tmp = end->next;
            revList(start, end->next);
            curr->next = end;
            start->next = tmp;
            curr = start;
        }
        return dummy->next;
    }
};
