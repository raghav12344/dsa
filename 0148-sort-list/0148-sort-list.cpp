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
    ListNode* findmiddle(ListNode *head)
    {
        ListNode *fp,*sp;
        fp=head;
        sp=head;
        while(fp->next!=NULL&&fp->next->next!=NULL)
        {
            fp=fp->next->next;
            sp=sp->next;
        }
        return sp;
    }
    ListNode* merge(ListNode *h1,ListNode* h2)
    {
        ListNode* h3=new ListNode(0);
        ListNode *ptr=h3;
        while(h1!=NULL && h2!=NULL)
        {
            if(h1->val<h2->val)
            {
                ptr->next=h1;
                ptr=ptr->next;
                h1=h1->next;
            }
            else
            {
                ptr->next=h2;
                ptr=ptr->next;
                h2=h2->next;
            }
        }
        if(h1!=NULL)
        {
            ptr->next=h1;
        }
        if(h2!=NULL)
        {
            ptr->next=h2;
        }
        return h3->next;

    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *mid=findmiddle(head);
        ListNode *left=head;
        ListNode *right=mid->next;
        mid->next=NULL;
        ListNode *rh1=sortList(left);
        ListNode *rh2=sortList(right);
        ListNode *res=merge(rh1,rh2);
        return res;
    }
};