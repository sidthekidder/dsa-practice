// https://leetcode.com/problems/diameter-of-binary-tree
// time complexity - O(N), space complexity - O(N)

class Solution 
{
public:
    int recur(TreeNode* root, int& maxD)
    {
        if (!root)
            return 0;
        int l = recur(root->left, maxD);
        int r = recur(root->right, maxD);
        maxD = max(maxD, l + r);
        return 1 + max(l, r);
    }
    
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int maxD = 0;
        recur(root, maxD);
        return maxD;
    }
};