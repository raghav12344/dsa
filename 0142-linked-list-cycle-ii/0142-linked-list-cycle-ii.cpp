/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
            return NULL;
        int flag=0;
        ListNode *fp=head,*sp=head;
        while(fp!=NULL && fp->next!=NULL)
        {
            fp=fp->next->next;
            sp=sp->next;
            if(fp==sp)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
            return NULL;
        sp=head;
        while(1)
        {
            if(fp==sp)
                break;
            fp=fp->next;
            sp=sp->next;
        }
        return sp;
    }
};