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
        int sz=0;
        ListNode *fast = head,*slow=NULL;
        while(n)
        {   
            fast = fast->next; --n;
        }
       
        if(fast == NULL) {
            head=head->next;
            return head;
        }
        slow = head;
        while(fast->next)
        {
            slow=slow->next; fast=fast->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};