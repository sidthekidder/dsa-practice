// https://leetcode.com/problems/merge-two-binary-trees
// time complexity - O(N), space complexity - O(N)

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) 
    {
        if (t1 && t2)
        {
            TreeNode *t3 = new TreeNode(t1->val + t2->val);
            t3->left = mergeTrees(t1->left, t2->left);
            t3->right = mergeTrees(t1->right, t2->right);
            return t3;
        }
        return (t1)? t1 : t2;
    }
};