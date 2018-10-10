// https://leetcode.com/problems/serialize-and-deserialize-binary-tree
// time complexity - O(N)

// input - binary tree
// required - serialize it in a string
// possible approaches - store it in above mentioned format

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        vector<string> result;
        while (!q.empty())
        {
            TreeNode* ele = q.front();
            q.pop();
            if (ele == NULL)
            {
                result.push_back("NULL");
            }
            else
            {
                string s = to_string(ele->val);
                result.push_back(s);
                q.push(ele->left);
                q.push(ele->right);
            }
        }
        // build the string
        stringstream ss;
        ss << "[";
        for(string s : result)
        {
            ss << s;
            ss << ", ";
        }
        ss << "]";
        // cout <<" Final string is: " << ss.str()<<endl;
        return ss.str();
    }
    
    void checkTree(TreeNode *root)
    {
        if (root != NULL)
        {
            if (root->left && root->left->val == -99)
                root->left = NULL;
            checkTree(root->left);
            
            if (root->right && root->right->val == -99)
                root->right = NULL;
            checkTree(root->right);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        data = data.substr(1, data.size() - 2); // remove opening, closing brackets
        vector<string> input;
        int idx = data.find(",");
        string s1;
        int cur = 0;
        while (idx != -1)
        {
            s1 = data.substr(0, idx);
            input.push_back(s1);
            data = data.substr(idx + 1);
            idx = data.find(",");
        }
        TreeNode *head = new TreeNode(-99);
        queue<TreeNode *> treeQ;
        treeQ.push(head);
        
        queue<string> q;
        for(string s : input)
            q.push(s);
        
        while (!q.empty())
        {
            string ele = q.front();
            q.pop();
            
            TreeNode *root = NULL;
            if (!treeQ.empty())
            {
                root = treeQ.front();
                treeQ.pop();
            }
            // cout << "Popped ele is x" << ele << "x"<<endl;

            if (ele.compare("NULL") == 0 || ele.compare(" NULL") == 0)
            {
                // cout << "1. Not inserting\n";
            }
            else
            {
                // cout << "2. Inserting in tree\n";
                root->val = stoi(ele);
                root->left = new TreeNode(-99);
                root->right = new TreeNode(-99);
                treeQ.push(root->left);
                treeQ.push(root->right);
            }
        }
        if (head->val == -99) head = NULL;
        checkTree(head);
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));