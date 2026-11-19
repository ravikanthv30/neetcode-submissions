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
        ListNode* list3 = NULL;
        
        if(list1==NULL && list2==NULL)
            return NULL;
        else if(list1==NULL)
            return list2;
        else if (list2==NULL)
            return list1;

        //fill the first one
        if(list1->val <= list2->val)
        {
            list3=new ListNode(list1->val);
            list1 = list1->next;
        }
        else
        {
            list3=new ListNode(list2->val);
            list2 = list2->next;
        }    

        ListNode* curr=list3;
        while(list1!=NULL && list2!=NULL)
        {
            int curr_val = 0;
            if(list1->val <= list2->val)
            {
                curr_val = list1->val;
                list1 = list1->next;
            }
            else
            {
                curr_val = list2->val;
                list2 = list2->next;
            }
            if(curr->next == NULL)
            {
                curr->next = new ListNode(curr_val);
                if(curr->next == NULL)
                    break;
                curr=curr->next;
            }
        }
        while(list1!=NULL)
        {
           if(curr->next == NULL)
            {
                curr->next = new  ListNode(list1->val);
                if(curr->next == NULL)
                    break;
                curr=curr->next;
                list1 = list1->next;
            }
        }
        while(list2!=NULL)
        {
           if(curr->next == NULL)
            {
                curr->next = new  ListNode(list2->val);
                if(curr->next == NULL)
                    break;
                curr=curr->next;
                list2 = list2->next;
            }
        }
        return list3;
    }
};
