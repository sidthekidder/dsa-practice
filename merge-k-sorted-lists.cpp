// https://leetcode.com/problems/merge-k-sorted-lists/
// time complexity - O(kN) (N = length of longest list), space complexity - O(1)

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // input - array of ListNode* - sorted lists in linkedlist format
        // output - single sorted list
        // 1. loop through all head pointers each time - quadratic complexity
        int numberOfLists = lists.size();
        int emptyLists = 0;
        ListNode* answer = NULL;
        ListNode* temp = NULL;
        while (emptyLists != numberOfLists)
        {
            ListNode *minNode = NULL;
            
            // get the min listnode pointer
            for(int i = 0 ; i < numberOfLists ; i++)
            {
                // check if head pointer null
                if (lists[i] == NULL) continue;
                
                if (minNode == NULL || lists[i]->val < minNode->val)
                {
                    minNode = lists[i];
                }
            }
            
            if (minNode == NULL) break;
            
            // put minNode to head of answer List
            if (temp == NULL) // first element to be added
            {
                answer = minNode;
                temp = minNode;
            }
            else
            {
                temp->next = minNode;
                temp = temp->next;
            }
            
            // increment that head pointer which we saved as minNode - search for it again
            for(int i = 0 ; i < numberOfLists ; i++)
            {
                // check if head pointer null
                if (lists[i] == minNode)
                {
                    lists[i] = lists[i]->next;
                    if (lists[i] == NULL) emptyLists++;
                }
            }
        }
        return answer;
    }
};