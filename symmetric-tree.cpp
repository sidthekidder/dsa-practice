// https://leetcode.com/problems/symmetric-tree
// time complexity - O(N), space complexity - O(N)

class Solution {
public:
    bool solve(TreeNode* r1, TreeNode* r2)
    {
        if (r1 == NULL && r2 == NULL)
            return true;
        if (r1 == NULL || r2 == NULL)
            return false;
        if (r1->val == r2->val)
            return solve(r1->left, r2->right) && solve(r1->right, r2->left);
        return false;
    }
    
    bool isSymmetric(TreeNode* root) 
    {
        if (root == NULL) return true;
        return solve(root->left, root->right);
    }
};