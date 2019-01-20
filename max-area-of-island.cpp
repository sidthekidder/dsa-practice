// https://leetcode.com/problems/max-area-of-island
// time complexity - O(MN), space complexity - O(MN)

class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& marked, int i, int j, int &count)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return;
        }
        if (marked[i][j] == true) {
            return;
        }
        if (grid[i][j] == 0) {
            return;
        }
        marked[i][j] = true;
        count++;
        dfs(grid, marked, i+1, j, count);
        dfs(grid, marked, i, j+1, count);
        dfs(grid, marked, i-1, j, count);
        dfs(grid, marked, i, j-1, count);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> marked(grid.size(), vector<bool>(grid[0].size(), false));
        int max_count = 0;
        for(int i = 0; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[0].size() ; j++)
            {
                if (grid[i][j] == 1 && marked[i][j] == false)
                {
                    int count = 0;
                    dfs(grid, marked, i, j, count);
                    max_count = max(count, max_count);
                }
            }
        }
        return max_count;
    }
};