// https://leetcode.com/problems/binary-tree-maximum-path-sum
// time complexity - O(N), space complexity - O(N)

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
    int recur(TreeNode* root, int& overallMax)
    {
        if (!root) return 0;
        
        int maxSumInLeftChild = max(recur(root->left, overallMax), 0);
        int maxSumInRightChild = max(recur(root->right, overallMax), 0);
        int maxSumTillNow = root->val + max(maxSumInLeftChild, maxSumInRightChild);
        
        overallMax = max(overallMax, root->val + maxSumInLeftChild + maxSumInRightChild);
        return maxSumTillNow;
    }
    
    int maxPathSum(TreeNode* root) {
        // each node should return 3 values
        // max sum seen till now = val + leftval + rightval
        // max sum in left child
        // max sum in right child
        int overallMax = INT_MIN;
        recur(root, overallMax);
        return overallMax;
    }
};