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
        vector<int> critical;
        while(ahead!=NULL)
        {
            if(ptr->val<prev->val && ptr->val<ahead->val)
                critical.push_back(idx);
            else if(ptr->val>prev->val && ptr->val>ahead->val)
                critical.push_back(idx);
            idx++;
            ahead=ahead->next;
            ptr=ptr->next;
            prev=prev->next;
        }
        if(critical.size()<=1)
            return {-1,-1};
        int mn=INT_MAX;
        for(int i=0;i<critical.size()-1;i++)
        {
            mn=min(critical[i+1]-critical[i],mn);
        }
        return {mn,critical[critical.size()-1]-critical[0]};
    }
};