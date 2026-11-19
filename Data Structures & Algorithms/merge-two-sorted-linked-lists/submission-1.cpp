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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1==NULL && list2==NULL)
            return NULL;
        else if(list1==NULL)
            return list2;
        else if (list2==NULL)
            return list1;
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(list1!=NULL && list2!=NULL)
        {
            if(list1->val <= list2->val)
            {
                curr->next = list1;
                list1 = list1->next;
            }
            else
            {
                curr->next = list2;
                list2 = list2->next; 
            }
            curr = curr->next;
        }
        // After the while loop breaks, attach whichever list has elements remaining
        if (list1 != NULL) {
            curr->next = list1;
        } else {
            curr->next = list2;
        }
        return dummy->next;
    }
};
