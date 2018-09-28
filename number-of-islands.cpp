// https://leetcode.com/problems/number-of-islands/
// time complexity - O(n^2), space complexity - O(n^2)
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& marked)
    {
        if (marked[i][j] == false)
        {
            marked[i][j] = true;
            
            // mark all neighbors
            if (i+1 < grid.size() && grid[i+1][j] == '1')
                dfs(grid, i+1, j, marked);
            if (i-1 >= 0 && grid[i-1][j] == '1')
                dfs(grid, i-1, j, marked);
            
            if (j+1 < grid[0].size() && grid[i][j+1] == '1')
                dfs(grid, i, j+1, marked);
            if (j-1 >= 0 && grid[i][j-1] == '1')
                dfs(grid, i, j-1, marked);
        }
    }
    
    int numIslands(vector<vector<char>>& grid)
    {
        // input - 2d grid
        // required - no of connected components
        // using tarjan's algorithm for finding SCC (dfs method)
        // O(number of elements) time, O(n) space
        // loop through each vertex and run dfs if its unmarked
        // count no of unmarked vertices
        vector<vector<bool>> marked;
        
        for(int i = 0 ; i < grid.size() ; i++)
        {
            vector<bool> row;
            for(int j = 0 ; j < grid[i].size() ; j++)
                row.push_back(false);
            
            marked.push_back(row);
        }
        int count = 0;
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[i].size() ; j++)
            {
                if (marked[i][j] == false && grid[i][j] == '1')
                {
                    count++;
                    dfs(grid, i, j, marked);
                }
            }
        }
        
        return count;
    }
};