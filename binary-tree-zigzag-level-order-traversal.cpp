// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal
// time complexity - O(N), space complexity - O(N)

class Solution 
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode*> bfs;
        bfs.push(root);
        
        int level = 0;
        while (!bfs.empty())
        {
            int qsize = bfs.size();
            vector<int> curVec(qsize);
            
            for(int i = 0 ; i < qsize ; i++)
            {
                TreeNode* ele = bfs.front();
                bfs.pop();
                
                if (level % 2 == 0)
                    curVec[i] = ele->val;
                else
                    curVec[qsize - i - 1] = ele->val;
                
                if (ele->left) bfs.push(ele->left);
                if (ele->right) bfs.push(ele->right);
            }
            result.push_back(curVec);
            level++;
        }
        return result;
    }
};