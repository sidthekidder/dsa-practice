// https://leetcode.com/problems/inorder-successor-in-bst
// time complexity - O(log H), space complexity - O(1)

class Solution {
public:    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) 
    {
        TreeNode *succ = NULL;
        while (root != NULL)
            if (p->val < root->val)
                succ = root, root = root->left;
            else
                root = root->right;
        return succ;
    }
};