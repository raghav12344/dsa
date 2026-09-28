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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>> pq;

        for(int i=0;i<lists.size();i++)
        {
            ListNode *ptr=lists[i];
            while(ptr!=NULL)
            {
                pq.push(ptr->val);
                ptr=ptr->next;
            }
        }
        ListNode *head=new ListNode(0);
        ListNode *ptr=head;
        while(!pq.empty())
        {
            ListNode* nn=new ListNode(pq.top());
            nn->next=NULL;
            pq.pop();
            ptr->next=nn;
            ptr=ptr->next;
        }
        return head->next;
    }
};