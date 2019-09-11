// https://leetcode.com/problems/is-graph-bipartite/submissions/
// time complexity - O(N), space complexity - O(N)

class Solution 
{
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        // return true if graph is bipartite
        // input - adjacency list representing graph
        // split nodes into 2 subsets such that every edge is from a to b
        // perform bfs on graph, each neighbor color 1 way
        // if any neighbor already has same color assigned, not possible
        
        queue<int> bfs;
        // initialize current colors size as -1
        vector<int> colors = vector<int>(graph.size(), -1);

        // loop over all nodes unless they are already colored
        for(int x = 0 ; x < graph.size() ; x++)
        {
            if (colors[x] != -1)
                continue;
            bfs.push(x); // start with 0th node
            colors[x] = 0; // color this node 
            while (!bfs.empty())
            {
                // get next element
                int ele = bfs.front();
                bfs.pop();

                // take this node's color and check against all neighbors if any 
                // node is colored opposite
                for(int i = 0 ; i < graph[ele].size() ; i++)
                {
                    int neighbor = graph[ele][i];
                    if (colors[neighbor] != -1)
                    {
                        // if neighbor is same color as current node
                        if (colors[neighbor] == colors[ele])
                            return false;
                    }
                    else
                    {
                        // color neighbor opposite of current node
                        colors[neighbor] = !colors[ele];
                        // push newly colored node into bfs
                        bfs.push(neighbor);
                    }
                }
            }
        }
        return true;
    }
};