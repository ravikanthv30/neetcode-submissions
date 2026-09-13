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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //2 1 
    //8 1  
    //- 1
    //0 3
    //BF: put into string and convert to number and add them 
    // iterative proces:  for loop till end of the lists l1, l2 --> add l1->val + l2->val + C => %10 - ret, C
    //time - O(n) & space -O(1)
    //edge cases: Null cases -- will be handled in below loop itself

    ListNode* dummy = new ListNode(0);
    ListNode *curr = dummy;
    int c = 0;
    while(l1 || l2 || c>0)
    {
        int sum = (l1?l1->val:0) + (l2?l2->val:0) + c;
        c = sum/10;
        int val = sum%10;
        curr->next = new ListNode(val);
        if(l1) 
            l1= l1->next;
        if(l2)
            l2=l2->next;
        curr = curr->next;
    }
     ListNode* ret = dummy->next;
     delete(dummy);
     return ret;
    }
};
