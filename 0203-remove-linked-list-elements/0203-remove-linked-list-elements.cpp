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
    ListNode* removeElements(ListNode* head, int val) {
        while(head!=NULL)
        {
            if(head->val==val)
                head=head->next;
            else 
                break;
        }
        ListNode *ptr=head;
        ListNode *prev=head;
        while(ptr!=NULL)
        {
            if(ptr->val==val)
            {
                prev->next=ptr->next;
                ptr=ptr->next;
            }
            else
            {
                prev=ptr;
                ptr=ptr->next;
            }
        }
        return head;
    }
};