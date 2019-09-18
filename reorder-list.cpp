// https://leetcode.com/problems/reorder-list/
// time complexity - O(N^2), space complexity - O(1)

class Solution {
public:
    ListNode* getLast(ListNode* node)
    {
        ListNode* prev = NULL;
        while (node->next != NULL)
        {
            prev = node;
            node = node->next;
        }
        if (prev) 
        {
            prev->next = NULL;
        }
        return node;
    }
    
    void reorderList(ListNode* head)
    {
        ListNode* cur = head;
                       
        while (cur != NULL && cur->next != NULL)
        {
            ListNode* temp = cur->next;

            cur->next = getLast(cur);
            cur = cur->next;

            if (temp != cur)
                cur->next = temp;
            cur = cur->next;
        }
    }
};