// https://leetcode.com/problems/binary-search-tree-iterator/

class BSTIterator {
public:
    queue<int> minQ;
    
    void BSTInorder(TreeNode *root)
    {
        if (root != NULL)
        {
            BSTInorder(root->left);
            minQ.push(root->val);
            BSTInorder(root->right);
        }
    }
    
    BSTIterator(TreeNode *root) {
        // perform in-order traversal and store nodes in queue - smallest node stored first
        BSTInorder(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (minQ.empty()) return false;
        else return true;
    }

    /** @return the next smallest number */
    int next() {
        // avg O(1) time, O(h) memory
        if (minQ.empty()) return -1;
        
        int ele = minQ.front();
        minQ.pop();
        return ele;
    }
};
