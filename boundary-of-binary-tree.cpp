// https://leetcode.com/problems/boundary-of-binary-tree
// time complexity - O(N), space complexity - O(N)


class Solution 
{
public:
    void printer(TreeNode* root, int dir, vector<int>& rec)
    {
        if (!root) return;
        
        // if left dir, push cur node and go to left child
        // if left child doesn't exist, go to right child
        
        // if right dir, push cur node and go to right child
        // if right child doesn't exist, go to left child
        
        // if leaf dir, push only if both children are dead
        // else go to left then right
        
        if (dir == 1) // left
        {
            // check if not leaf node
            if (root->left || root->right)
            {
                rec.push_back(root->val);
                if (root->left)
                    printer(root->left, dir, rec);
                else
                    printer(root->right, dir, rec);
            }
            return;
        }
        else if (dir == 2) // leaf
        {
            if (!root->left && !root->right)
                rec.push_back(root->val);
            else
            {
                if (root->left)
                    printer(root->left, dir, rec);
                if (root->right)
                    printer(root->right, dir, rec);
            }
        }
        else if (dir == 3) // right
        {
            // check for leaf node
            if (root->left || root->right)
            {
                rec.push_back(root->val);
                if (root->right)
                    printer(root->right, dir, rec);
                else
                    printer(root->left, dir, rec);
            }
            return;
        }
    }
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) 
    {
        if (!root) return vector<int>();
        vector<int> left, leaf, right;
        left.push_back(root->val);
        if (root->left)
            printer(root->left, 1, left);
            
        printer(root->left, 2, leaf);
        printer(root->right, 2, leaf);

        if (root->right)
            printer(root->right, 3, right);
        
        vector<int> res(left.begin(), left.end());
        res.insert(res.end(), leaf.begin(), leaf.end());
        reverse(right.begin(), right.end());
        res.insert(res.end(), right.begin(), right.end());
        return res;
    }
};
