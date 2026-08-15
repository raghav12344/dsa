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
        int count=0;
        ListNode *ptr=head;
        while (ptr!=NULL)
        {
            ptr=ptr->next;
            count++;
        }
        count=count-n-1;
        if(count<0)
            return head->next;
        else
        {
            ptr=head;
            while(count!=0)
            {
                ptr=ptr->next;
                count--;
            }
            ptr->next=ptr->next->next;
        }
        return head;
    }
};