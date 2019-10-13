// https://leetcode.com/problems/serialize-and-deserialize-binary-tree
// time complexity - O(N), space complexity - O(N)

class Codec 
{
public:
    
    void serializeHelper(TreeNode* root, ostringstream& out)
    {
        if (root == NULL)
            out << "# ";
        else
        {
            out << root->val << " ";
            serializeHelper(root->left, out);
            serializeHelper(root->right, out);
        }
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        ostringstream out;
        serializeHelper(root, out);
        return out.str();
    }
    
    TreeNode* deserializeHelper(istringstream& in)
    {
        string ch;
        in >> ch;
        if (ch == "#")
            return NULL;
        
        TreeNode *ptr = new TreeNode(stoi(ch));
        ptr->left = deserializeHelper(in);
        ptr->right = deserializeHelper(in);
        return ptr;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        istringstream in(data);
        return deserializeHelper(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));