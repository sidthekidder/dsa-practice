// https://leetcode.com/problems/merge-k-sorted-lists/
// time complexity - O(k + nlogk), space complexity - O(k)

class Comparator
{
    public:
    bool operator() (ListNode* a, ListNode* b)
    {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        // push all list heads into min priority_queue and insert min node into result each time
        // keep doing so until all lists are empty
        ListNode* head = NULL;
        ListNode* result = NULL;
        priority_queue<ListNode*, vector<ListNode*>, Comparator> pq;

        for(int i = 0 ; i < lists.size() ; i++)
            if (lists[i] != NULL)
                pq.push(lists[i]);
        
        while (!pq.empty())
        {
            // get min value node and pop from queue
            ListNode* min_node = pq.top();
            pq.pop();

            // insert into result
            if (!result) 
            {
                result = min_node;
                head = min_node;
            }
            else 
            {
                result->next = min_node;
                result = result->next;
            }
            
            // insert next node after min_node
            if (min_node->next != NULL)
                pq.push(min_node->next);            
        }
        return head;
    }
};