// https://leetcode.com/problems/surrounded-regions/
// time complexity - O(n^2) (dfs SCC), space complexity - O(n^2)

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& marked)
    {
        if (i < grid.size() && i >= 0 && j < grid[0].size() && j >= 0 && !marked[i][j] && grid[i][j] == 'O')
        {
            marked[i][j] = true;
            
            // mark all eligible neighbors
            if (i+1 < grid.size() && grid[i+1][j] == 'O')
                dfs(grid, i+1, j, marked);
            if (i-1 >= 0 && grid[i-1][j] == 'O')
                dfs(grid, i-1, j, marked);
            
            if (j+1 < grid[0].size() && grid[i][j+1] == 'O')
                dfs(grid, i, j+1, marked);
            if (j-1 >= 0 && grid[i][j-1] == 'O')
                dfs(grid, i, j-1, marked);
        }
    }
    
    void solve(vector<vector<char>>& grid)
    {
        // input - 2d grid
        // required - no of connected components
        // using tarjan's algorithm for finding SCC (dfs method) for all 4 borders
        // run dfs if its unmarked and set marked[i][j] = true if == '0'
        // now where marked[i][j] is false set to 'X'
        vector<vector<bool>> marked;
        if (grid.size() == 0) return;
        
        for(int i = 0 ; i < grid.size() ; i++)
        {
            vector<bool> row;
            for(int j = 0 ; j < grid[i].size() ; j++)
                row.push_back(false);
            
            marked.push_back(row);
        }
        int count = 0;
        for(int j = 0 ; j < grid[0].size() ; j++)
        {
            // top row
            if (!marked[0][j] && grid[0][j] == 'O')
            {
                dfs(grid, 0, j, marked);
            }
            // bottom row
            if (!marked[grid.size()-1][j] && grid[grid.size()-1][j] == 'O')
            {
                dfs(grid, grid.size()-1, j, marked);
            }
        }
        
        for(int i = 0 ; i < grid.size() ; i++)
        {
            // left row
            if (!marked[i][0] && grid[i][0] == 'O')
            {
                dfs(grid, i, 0, marked);
            }
            // right row
            if (!marked[i][grid[0].size()-1] && grid[i][grid[0].size()-1] == 'O')
            {
                dfs(grid, i, grid[0].size()-1, marked);
            }
        }
        // now turn all marked[false] cells as false
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[0].size() ; j++)
            {
                cout << marked[i][j];
                if (!marked[i][j]) grid[i][j] = 'X';
            }
            cout<<endl;
        }
    }
};