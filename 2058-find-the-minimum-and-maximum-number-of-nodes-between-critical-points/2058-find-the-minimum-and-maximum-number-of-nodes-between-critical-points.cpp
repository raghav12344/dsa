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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==NULL|| head->next==NULL|| head->next->next==NULL)
            return{-1,-1};
        ListNode *prev=head;
        ListNode *ptr=head->next;
        ListNode *ahead=head->next->next;
        int idx=0;
        int first=-1;
        int last=-1;
        int mn=INT_MAX;
        while(ahead!=NULL)
        {
            if((ptr->val<prev->val && ptr->val<ahead->val) || (ptr->val>prev->val && ptr->val>ahead->val))
            {
                if(first==-1)
                    first=idx;
                if(last!=-1)
                    mn=min(mn,idx-last);
                last=idx;
            }
            
            idx++;
            ahead=ahead->next;
            ptr=ptr->next;
            prev=prev->next;
        }
        if(first==-1 || first==last)
            return {-1,-1};
        return {mn,last-first};
    }
};