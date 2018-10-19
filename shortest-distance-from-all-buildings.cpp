// https://leetcode.com/problems/shortest-distance-from-all-buildings
// time complexity - O(no of buildings * MN), space complexity - O(no of empty spaces * MN)

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int dist, vector<vector<int>>& distances)
    {
        if (i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size() && (grid[i][j] == 0 || dist == 0) && distances[i][j] > dist)
        {
            distances[i][j] = dist;
            dfs(grid, i+1, j, dist+1, distances);
            dfs(grid, i, j+1, dist+1, distances);
            dfs(grid, i-1, j, dist+1, distances);
            dfs(grid, i, j-1, dist+1, distances);
        }
    }
    
    int shortestDistance(vector<vector<int>>& grid) 
    {
        // for each 0, save the dist from each building
        // from each building, carry out dfs
        // loop over all 0s, sum all the distances and keep the min one so far
        
        vector<vector<vector<int>>> dist_arrs;
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[0].size() ; j++)
            {
                if (grid[i][j] == 1)
                {
                    vector<vector<int>> distances(grid.size(), vector<int>(grid[0].size(), numeric_limits<int>::max()));
                    dfs(grid, i, j, 0, distances);
                    dist_arrs.push_back(distances);
                }
            }
        }
        
        int minDist = numeric_limits<int>::max();
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[0].size() ; j++)
            {
                if (grid[i][j] == 0)
                {
                    int sum = 0;
                    bool skipFlag = false;
                    for(int a = 0 ; a < dist_arrs.size() ; a++)
                    {
                        if (dist_arrs[a][i][j] == numeric_limits<int>::max())
                        {
                            skipFlag = true;
                            break;
                        }
                        sum += dist_arrs[a][i][j];
                    }
                    if (!skipFlag)
                        minDist = min(minDist, sum);
                }
            }
        }
        return (minDist == numeric_limits<int>::max())? -1 : minDist;
    }
};