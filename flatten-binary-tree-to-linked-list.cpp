// https://leetcode.com/problems/flatten-binary-tree-to-linked-list
// time - O(N), space - O(1)

class Solution 
{
public:
    void flatten(TreeNode* root) 
    {
        if (root == NULL) 
            return;
        if (root->left && root->right)
        {
            TreeNode* temp = root->right;
            root->right = root->left;
            root->left = NULL;
            TreeNode* rightmost = root->right;
            while (rightmost->right != NULL)
            {
                rightmost = rightmost->right;
            }
            rightmost->right = temp;
            flatten(root->right);
        }
        else if (root->left)
        {
            root->right = root->left;
            root->left = NULL;
            flatten(root->right);
        }
        else if (root->right)
        {
            flatten(root->right);
        }
    }
};