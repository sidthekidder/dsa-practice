// https://leetcode.com/problems/friend-circles/
// time complexity - O(N^2), space complexity - O(N^2)

class Solution {
public:
    void recurse(vector<vector<int>>& M, int i, int j, vector<vector<bool>>& visited)
    {
        if (visited[i][j]) 
            return;
        
        visited[i][j] = true;
        for(int x = 0 ; x < M[j].size() ; x++)
            if (M[j][x] == 1)
                recurse(M, j, x, visited);
    }
    
    int findCircleNum(vector<vector<int>>& M) 
    {
        vector<vector<bool>> visited(M.size(), vector<bool>(M[0].size(), false));
        int count = 0;
        for(int i = 0 ; i < M.size() ; i++)
            for(int j = 0 ; j < M[0].size() ; j++)
                if (M[i][j] == 1 && !visited[i][j])
                    recurse(M, i, j, visited), count++;
        
        return count;
    }
};