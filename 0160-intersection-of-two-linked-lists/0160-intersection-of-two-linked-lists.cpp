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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1=headA;
        ListNode *ptr2=headB;
        int n=0;
        while(ptr1!=NULL)
        {
            n++;
            ptr1=ptr1->next;
        }
        int m=0;
        while(ptr2!=NULL)
        {
            m++;
            ptr2=ptr2->next;
        }
        ptr1=headA;
        ptr2=headB;
        if(m>n)
        {
            for(int i=0;i<abs(n-m);i++)
            {
                ptr2=ptr2->next;
            }
        }
        else if(n>m)
        {
            for(int i=0;i<abs(n-m);i++)
            {
                ptr1=ptr1->next;
            }
        }

        while(ptr1!=NULL&&ptr2!=NULL&&ptr1!=ptr2)
        {
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        return ptr1;
    }
};