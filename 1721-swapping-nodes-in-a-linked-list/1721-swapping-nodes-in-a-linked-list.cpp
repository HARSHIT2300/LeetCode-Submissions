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
    ListNode* swapNodes(ListNode* head, int k) {
     
        ListNode *slow=head,*fast=head,*slow1;
        int k1 = k;
        while(k1>1)
        {
            k1--; fast = fast->next;
        }
        slow1  = fast;
        while(fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        int vl = slow1->val;
        slow1->val = slow->val;
        slow->val = vl;
        return head;
    }
};