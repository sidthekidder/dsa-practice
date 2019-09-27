// https://leetcode.com/problems/binary-tree-right-side-view
// time complexity - O(N), space complexity - O(N)

class Solution 
{
public:
    int getHeight(TreeNode* root)
    {
        if (!root) return NULL;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
    
    vector<int> rightSideView(TreeNode* root) 
    {
        if (!root) return vector<int>();
        // perform bfs from root
        // insert node,level pairs
        // use level as index of array
        queue<pair<TreeNode*, int>> bfs;
        bfs.push({root, 0});
        
        int height = getHeight(root);
        vector<int> finalarr(height, -1);
        
        while (!bfs.empty())
        {
            pair<TreeNode*, int> ele = bfs.front();
            bfs.pop();
            
            finalarr[ele.second] = ele.first->val;
            
            // push children
            if (ele.first->left)
                bfs.push({ele.first->left, ele.second+1});
            if (ele.first->right)
                bfs.push({ele.first->right, ele.second+1});
        }
        return finalarr;
    }
};