// https://leetcode.com/problems/search-a-2d-matrix-ii/
// time complexity - O(M+N), space complexity - O(1)

class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        
        int yi = matrix[0].size() - 1, xi = 0;
        while (xi >= 0 && yi >= 0 && xi < matrix.size())
        {
            if (target > matrix[xi][yi])
                xi++;
            else if (target < matrix[xi][yi])
                yi--;
            else if (target == matrix[xi][yi])
                return true;
        }
        return false;
    }
};