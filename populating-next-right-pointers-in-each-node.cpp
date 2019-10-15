// https://leetcode.com/problems/populating-next-right-pointers-in-each-node
// time complexity - O(N), space complexity - O(N)

class Solution 
{
public:
    Node* connect(Node* root) 
    {
        if (!root) return root;
        // perform bfs for level order traversal
        queue<Node*> bfs;
        bfs.push(root);
        // 1, 2, 4, 8 etc -> pow(2, i) number of nodes
        int i = 0;
        int counter = 0;
        while (!bfs.empty()) // counter = 0, i = 1
        {
            Node* ele = bfs.front();
            bfs.pop();
            counter++; // c=2
            
            // make next pointer point to next node on top of bfs
            if (counter == pow(2, i)) // 2 == 2
            {
                ele->next = NULL;
                i++;
                counter = 0;
            }
            else
                ele->next = bfs.front();
            
            // push children
            if (ele->left) bfs.push(ele->left);
            if (ele->right) bfs.push(ele->right);
        }
        return root;
    }
};