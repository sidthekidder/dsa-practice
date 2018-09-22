// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/
// time complexity - O(N log N)
// space complexity - O(N)
class Solution {
public:
    struct comparer
    {
        bool operator()(const int &a,  const int &b)
        {
            return a > b;
        }
    };
    
    void traverseTree(TreeNode* root, priority_queue<int, vector<int>, comparer> &pq)
    {
        if (root != NULL)
        {
            traverseTree(root->left, pq);
            pq.push(root->val);
            traverseTree(root->right, pq);
        }
    }
    
    int findSecondMinimumValue(TreeNode* root)
    {
        priority_queue<int, vector<int>, comparer> pq;
        traverseTree(root, pq);
        if (pq.size() == 1) return -1;
        int ele, ele2;
        ele = pq.top();
        pq.pop();
        ele2 = pq.top();
        pq.pop();
        

        while (!pq.empty() && ele == ele2)
        {
            ele2 = pq.top();
            pq.pop();
        }
        if (pq.empty() && ele == ele2) return -1;
        return ele2;
    }
};