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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //brute force method -> covert all of them into single arrays and sort it -> o(nlogn) & space o(n)
        //optimal - run one loop with all K lists and move each list pointer based on the values as they are alraedy sorted
        //psuedo algo : 
        //while (bool is_all list empty == false)
        //for loop of K -> if all are NULL set is_all_list = true;
        //ret_list -> get all elements in that index (non-null) and move it to result a sorted array 
        //return ret_list
        //o(n - longest length) -  o(k) space
        //edge cases: empty list return back, k=0 - return [], k=1 - return same input list

        //that wont work -->  same mistake; trying to combine lot of things into one loop !! split and do
        // mergeKLists = merge 2 lists at a time move forward with what is lesser value 
        //  take 0 as ret_list ; for - 1-k => try to merge each list 
/*
        if(lists.size()==0)
            return NULL;
        if(lists.size()==1)
            return lists[0];

        ListNode *ret=NULL;
        ListNode *merge_list= lists[0];
        for(int i=1; i<lists.size(); i++)
        {
          merge_list = mergeTwoLists(merge_list, lists[i]);
          ret = merge_list;
        }
        return ret;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1==NULL && list2==NULL)
            return NULL;
        else if(list1==NULL)
            return list2;
        else if (list2==NULL)
            return list1;
        ListNode dummy(0);
        ListNode* head = &dummy;
        ListNode* curr = &dummy;
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
        return head->next;
*/

    //So idea is to 
    // 1. take first k set of nodes into priorityQ 
    // 2. for those K nodes pick lowest(pq.pop) 
    // 3. when you take out a node from a list then push next node to pq

    if(!lists.size())
        return nullptr;

    struct Compare {
        bool operator()(const ListNode* a, const ListNode* b)
        {
            return a->val > b->val; 
        }
    };
    priority_queue <ListNode*, vector<ListNode *>, Compare> min_pq;

    //push only first nodes of k lists
    for(ListNode* l: lists)
    {
        if(l)
            min_pq.push(l);
    }

    ListNode* dummy = new ListNode(0);
    ListNode* ret = dummy;
    while(!min_pq.empty())
    {
        ListNode* minNode = min_pq.top();
        min_pq.pop();
        dummy->next = minNode;
        if(minNode->next)
        {
            min_pq.push(minNode->next);
        }
        dummy = dummy->next;
    }
    
    return ret->next;

    }

};
