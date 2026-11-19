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
    ListNode* reverseList(ListNode* head) {
        ListNode * curr = NULL, *prev = NULL, *next = NULL;
        curr = head;        
        while(curr != NULL)
        {
            next = curr->next;
          //  cout << prev << "-p " << curr << "=c " << next << "=n " << endl;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        //cout << "Final" <<prev << "-p " << curr << "=c " << next << "=n " << endl;
        head = prev;
        return head;
    }
};
