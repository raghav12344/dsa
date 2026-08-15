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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res=new ListNode(0);
        ListNode* ptr=res;
        int cary=0;
        while(l1!=NULL&&l2!=NULL)
        {
            int val=l1->val+l2->val;
            val=val+cary;
            if(val/10==0)
            {
                val=val;
                cary=0;
            }
            else
            {
                val=val%10;
                cary=1;
            }
            ListNode *nn=new ListNode(val);
            ptr->next=nn;
            ptr=ptr->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL)
        {
            int val=l1->val;
            val=val+cary;
            if(val/10==0)
            {
                val=val;
                cary=0;
            }
            else
            {
                val=val%10;
                cary=1;
            }
            ListNode *nn=new ListNode(val);
            ptr->next=nn;
            l1=l1->next;
            ptr=ptr->next;
        }
        while(l2!=NULL)
        {
            int val=l2->val;
            val=val+cary;
            if(val/10==0)
            {
                val=val;
                cary=0;
            }
            else
            {
                val=val%10;
                cary=1;
            }
            ListNode *nn=new ListNode(val);
            ptr->next=nn;
            l2=l2->next;
            ptr=ptr->next;
        }
        if(cary==1)
        {
            ListNode *nn=new ListNode(1);
            ptr->next=nn;
        }
        return res->next;
    }
};