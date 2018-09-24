// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree
// Time complexity - exponential, space complexity - exponential on call stack
class Solution {
public:
    bool existsInChild(TreeNode* root, TreeNode* check)
    {
        if (root == NULL || check == NULL) return false;
        
        if (root->val == check->val) return true;
        return existsInChild(root->left, check) || existsInChild(root->right, check);
    }
    
    TreeNode* bt_lca(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        // case 1 - p in left child and q in right child - lca found, 
        // case 2 - p & q both in right or both in left children - go deeper
        // case 3 - p is root and q is in right/left child
        if (root == NULL) return NULL;
        
        bool pInLeft = existsInChild(root->left, p);
        bool qInRight = existsInChild(root->right, q);
        
        // check case 3
        if (root->val == p->val || root->val == q->val)
        {
            if (pInLeft && !qInRight) return q;
            if (!pInLeft && qInRight) return p;
        }
        
        // check case 1
        if ((pInLeft && qInRight) || (!pInLeft && !qInRight))
        {
            return root;
        }
        
        // check case 2
        if (pInLeft && !qInRight)
            return bt_lca(root->left, p, q);
        else if (!pInLeft && qInRight)
            return bt_lca(root->right, p, q);
        
        return NULL;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        return bt_lca(root, p, q);
    }
};