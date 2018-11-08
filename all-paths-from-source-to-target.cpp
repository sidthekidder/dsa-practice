// https://leetcode.com/problems/all-paths-from-source-to-target/
// time complexity - O(n^k) (exponential)

class Solution {
public:
    void getPath(vector<vector<int>>& graph, vector<vector<int>>& results, int idx, vector<int> current)
    {
        if (idx == graph.size() - 1)
        {
            current.push_back(idx);
            results.push_back(current);
            return;
        }
        current.push_back(idx);
        for(int i = 0 ; i < graph[idx].size() ; i++)
            getPath(graph, results, graph[idx][i], current);
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<vector<int>> results;
        vector<int> current;
        getPath(graph, results, 0, current);
        return results;
    }
};