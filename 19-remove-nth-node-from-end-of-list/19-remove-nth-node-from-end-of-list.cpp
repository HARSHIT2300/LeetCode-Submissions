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
        ListNode *tmp = head;
        while(tmp != NULL)
        {
            tmp = tmp->next; ++sz;
        }
        sz = sz - n;
        if(sz == 0) {
            head=head->next;
            return head;
        }
        tmp = head;
        for(int i=1;i<sz;i++)
        {
            tmp = tmp -> next;
        }
        tmp->next = tmp->next->next;
        return head;
    }
};