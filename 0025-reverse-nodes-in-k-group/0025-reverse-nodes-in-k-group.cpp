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
    ListNode * join(ListNode* head1,ListNode *head2)
    {
        if (head1 == nullptr)
            return head2;

        ListNode* temp = head1;

        while (temp->next != nullptr) 
        {
            temp = temp->next;
        }

        temp->next = head2;

        return head1;
    }
    ListNode *reverse(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *rest = reverse(head->next);
        head->next->next = head;
        head->next = NULL;

        return rest;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL)
        return NULL;

        ListNode* ptr = head;

        for (int i = 1; i < k; i++) 
        {
            if (ptr == NULL || ptr->next == NULL)
                return head;
            ptr = ptr->next;
        }

        ListNode* l2 = ptr->next;
        ptr->next = NULL;

        head = reverse(head);
        l2 = reverseKGroup(l2, k);

        return join(head, l2);
    }
};