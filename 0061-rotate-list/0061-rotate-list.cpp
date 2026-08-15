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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *ptr=head;
        int len=0;

        while(ptr!=NULL)
        {
            len++;
            ptr=ptr->next;
        }
        if(len==0||k==0 || len==1)
            return head;
        ptr=head;
        k=k%len;
        if(k==0)
            return head;
        for(int i=0;i<len-k-1;i++)
        {
            ptr=ptr->next;
        }
        ListNode*l2=ptr->next;
        ptr->next=NULL;

        ptr=l2;
        while(ptr->next!=NULL)
            ptr=ptr->next;
        
        ptr->next=head;

        return l2;
    }
};