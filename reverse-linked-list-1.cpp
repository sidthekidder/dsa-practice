// https://leetcode.com/problems/reverse-linked-list
// time complexity - O(N), space complexity - O(1)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) 
            return head;

        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* tmp = head->next;
        
        while (cur != NULL)
        {
            cur->next = prev;
            prev = cur;
            cur = tmp;
            if (tmp)
                tmp = tmp->next;
        }
        return prev;
    }
};