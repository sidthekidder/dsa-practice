// https://leetcode.com/problems/subtree-of-another-tree/
// time complexity - O(nodes in s * nodes in t) 

class Solution {
public:
    bool sameTreeCheck(TreeNode* s, TreeNode* t)
    {
        if (s == NULL && t == NULL) return true;
        if (s == NULL || t == NULL) return false;
        
        if (s->val == t->val)
            return sameTreeCheck(s->left, t->left) && isSubtree(s->right, t->right);
        else
            return false;
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) 
    {
        if (s == NULL && t == NULL) return true;
        if (s == NULL || t == NULL) return false;
        
        if (s->val == t->val)
            return ((sameTreeCheck(s->left, t->left) && isSubtree(s->right, t->right)) || 
                    isSubtree(s->left, t) || 
                    isSubtree(s->right, t));
        else
            return isSubtree(s->right, t) || isSubtree(s->left, t);
    }
};
