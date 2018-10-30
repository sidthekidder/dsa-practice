// https://leetcode.com/problems/zigzag-conversion/
// time complexity - O(M), space complexity - ?

class Solution {
public:
    string convert(string s, int numRows) 
    {
        if (numRows == 1) return s;
        int len = s.length();
        int str_len = len;
        int numCols = 0;
        
        // get number of columns
        while (str_len > 0)
        {
            str_len -= numRows;
            numCols += 1;
            if (str_len > 0 && numRows > 2)
            {
                str_len -= (numRows - 2);
                numCols += (numRows - 2);
            }
            else if (str_len > 0 && numRows <= 2)
            {
                str_len -= numRows;
                numCols += numRows;
            }
        }
        vector<vector<char>> grid(numRows, vector<char>(numCols, 'X'));
        int i = 0, j = 0;
        int s_idx = 0;
        int dir = 0; // 0 - down, 1 - up
        while (true)
        {
            if (s_idx == s.length())
                break;
            grid[i][j] = s[s_idx++];
            if (dir == 0)
            {
                if (i < numRows - 1)
                    i++;
                else if (i == numRows - 1)
                {
                    dir = 1;
                    j++;
                    if (i > 0)
                        i--;
                }
            }
            else if (dir == 1)
            {
                if (i > 0)
                    i--;
                else if (i == 0)
                {
                    dir = 0;
                    j--;
                    i++;
                }
                j++;
            }
        }
        
        // print out the grid in normal order
        stringstream ss;
        for(i = 0 ; i < numRows ; i++)
        {
            for(j = 0 ; j < numCols ; j++)
            {
                if (grid[i][j] != 'X')
                    ss << grid[i][j];
            }
        }
        
        return ss.str();
    }
};