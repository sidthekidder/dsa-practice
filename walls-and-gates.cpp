// https://leetcode.com/problems/walls-and-gates
// time complexity - O(MN), space complexity - O(1)

class Solution {
public:
    void dfsHelper(vector<vector<int>>& rooms, int i, int j, int dist)
    {
        if (i < rooms.size() && i >= 0 && j < rooms[0].size() && j >= 0 && rooms[i][j] != -1 && (rooms[i][j] > dist || dist == 0))
        {
            rooms[i][j] = dist;
            dfsHelper(rooms, i+1, j, dist + 1);
            dfsHelper(rooms, i, j+1, dist + 1);
            dfsHelper(rooms, i-1, j, dist + 1);
            dfsHelper(rooms, i, j-1, dist + 1);
        }
    }
    
    void wallsAndGates(vector<vector<int>>& rooms) 
    {
        // run dfs from each gate in all directions and update shortest distance
        for(int i = 0 ; i < rooms.size() ; i++)
            for(int j = 0 ; j < rooms[0].size() ; j++)
                if (rooms[i][j] == 0)
                    dfsHelper(rooms, i, j, 0);
};