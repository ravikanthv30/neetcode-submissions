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
    bool hasCycle(ListNode* head) {
        //as this is signle linked list only one way to move
        //heap counting the visted nodes to see if i have already visted it or not 
        //have 2 poiters slow and fast --> if they meet cycle is there else no cycle
        
  /*      unordered_map<ListNode*, int> m;
        ListNode* curr = head;
        while(curr!=NULL)
        {
            if(m[curr] >= 1)
                return true;
            m[curr]++;
            curr = curr->next;
        }
        return false;
*/

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(fast == slow)
                return true;
        }
        return false;
    }
};
