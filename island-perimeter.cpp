// https://leetcode.com/problems/island-perimeter
// time complexity - O(N^2), space complexity - O(1)

class Solution {
public:
    int get_neighbors(vector<vector<int>>& grid, int i, int j)
    {
        int count = 0;
        if (i+1 < grid.size())
            count += (grid[i+1][j] == 1)? 1 : 0;
        if (j+1 < grid[0].size())
            count += (grid[i][j+1] == 1)? 1 : 0;
        if (i-1 >= 0)
            count += (grid[i-1][j] == 1)? 1 : 0;
        if (j-1 >= 0)
            count += (grid[i][j-1] == 1)? 1 : 0;
        return count;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        int count = 0;
        for(int i = 0 ; i < grid.size() ; i++)
            for(int j = 0 ; j < grid[0].size() ; j++)
                if (grid[i][j] == 1)
                    count += 4 - get_neighbors(grid, i, j);

        return count;
    }
};