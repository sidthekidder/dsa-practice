/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
        pair<pair<bool, int>, pair<int, int>> ret = validBSTHelper(root);
        return ret.first.first;
    }
    
    pair<pair<bool, int>, pair<int, int>> validBSTHelper(TreeNode* root)
    {
        if (root == NULL) 
        {
            return pair<pair<bool, int>, pair<int, int>>(pair<bool, int>(true, 0), pair<int, int>(0, 0));
        }

        // true/false overall, no of nodes, left min, right max
        pair<pair<bool, int>, pair<int, int>> left = validBSTHelper(root->left);
        pair<pair<bool, int>, pair<int, int>> right = validBSTHelper(root->right);

        if ((left.first.first && right.first.first) &&  // both subtrees are valid BSTs
            (!root->left || root->val > left.second.second) && // check if root is greater than max in left subtree
            (!root->right || root->val < right.second.first)) // check if root is smaller than min in right subtree
        {
            pair<bool, int> bi = pair<bool, int>(true, 1 + left.first.second + right.first.second);
            int i1, i2;
            if (!root->left)
                i1 = root->val;
            else
                i1 = left.second.first;
            if (!root->right)
                i2 = root->val;
            else
                i2 = right.second.second;

            pair<int, int> ii = pair<int, int>(i1, i2);
            return pair<pair<bool, int>, pair<int, int>>(bi, ii);                
        }
        else    // if either subtree isn't a BST
        {
            pair<bool, int> bi = pair<bool, int>(false, 0);
            pair<int, int> ii = pair<int, int>(0, 0);
            return pair<pair<bool, int>, pair<int, int>>(bi, ii);
        }
    }
};