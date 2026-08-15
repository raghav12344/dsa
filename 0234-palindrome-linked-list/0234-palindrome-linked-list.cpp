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
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        ListNode *ptr=head;
        int len=0;
        while(ptr!=NULL)
        {
            len++;
            ptr=ptr->next;
        }
        ptr=head;
        for(int i=0;i<len/2;i++)
        {
            arr.push_back(ptr->val);
            ptr=ptr->next;
        }
        if(len%2==1)
        {
            arr.push_back(ptr->val);
        }
        for(int i=arr.size()-1;i>=0;i--)
        {
            if(arr[i]!=ptr->val)
            {
                return false;
            }
            ptr=ptr->next;
        }
        return true;
    }
};