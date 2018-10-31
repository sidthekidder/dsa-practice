// https://leetcode.com/problems/toeplitz-matrix
// time complexity - O(N^2), space complexity - O(N^2)

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) 
    {
        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
        for(int i = 0 ; i < matrix.size() ; i++)
        {
            for(int j = 0 ; j < matrix[i].size() ; j++)
            {
                if (!visited[i][j])
                {
                    int i1 = i+1, j1 = j+1;
                    visited[i][j] = true;
                    while (i1 < matrix.size() && j1 < matrix[i].size())
                    {
                        if (matrix[i1][j1] != matrix[i][j])
                            return false;
                        visited[i1][j1] = true;
                        i1++, j1++;
                    }
                }
            }
        }
        return true;
    }
};