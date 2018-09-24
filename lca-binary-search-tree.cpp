// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

class Solution {
public:
    TreeNode* bst_LCA(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == NULL) return NULL;
        
        if (root->val > p->val && root->val > q->val)
            return bst_LCA(root->left, p, q); // search in left subtree
        else if (root->val < p->val && root->val < q->val)
            return bst_LCA(root->right, p, q); // search in right subtree
        else // this is the lca
            return root;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        return bst_LCA(root, p, q);
    }
};