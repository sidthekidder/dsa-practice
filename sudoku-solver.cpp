// https://leetcode.com/problems/sudoku-solver
// time complexity - O(9^n) exponential

class Solution {
public:
    vector<int> getPossibleValues(const vector<vector<char>>& board, int i1, int j1) 
    {
        vector<int> result; 
        bool visited[10] = {false};

        // mark row values as visited
        for(int i = 0 ; i < 9 ; i++)
            if (board[i1][i] != '.')
                visited[board[i1][i] - '0'] = true;

        // mark col values as visited
        for(int i = 0 ; i < 9 ; i++)
            if (board[i][j1] != '.')
                visited[board[i][j1] - '0'] = true;

        // mark 3x3 around the cell as visited
        int i_lo, i_hi, j_lo, j_hi;
        if (i1 <= 2) 
            i_lo = 0, i_hi = 2;
        else if (i1 > 2 && i1 <= 5)
            i_lo = 3, i_hi = 5;
        else
            i_lo = 6, i_hi = 8;

        if (j1 <= 2)
            j_lo = 0, j_hi = 2;
        else if (j1 > 2 && j1 <= 5)
            j_lo = 3, j_hi = 5;
        else
            j_lo = 6, j_hi = 8;

        // mark 3x3 grid values as visited
        for(int a = i_lo ; a <= i_hi ; a++)
            for(int b = j_lo ; b <= j_hi ; b++)
                if (board[a][b] != '.')
                    visited[board[a][b] - '0'] = true;

        // push unvisited values to vector
        for(int i = 1 ; i <= 9 ; i++)
            if (!visited[i])
                result.push_back(i);

        return result;
    }
    
    void solveSudokuRecursive(vector<vector<char>>& board, bool &solved)
    {
        // input - 9x9 grid of characters
        // output - single bool
        // bool visited[9] 3x3, row, column
        // get the list of possible numbers for each cell
        int minLengthVector = 10;
        vector<int> minV;
        int minI = 0, minJ = 0;
        for(int i = 0 ; i < 9 ; i++)
        {
            for(int j = 0 ; j < 9 ; j++)
            {
                if (board[i][j] == '.')
                {
                    vector<int> possibleValues = getPossibleValues(board, i, j);

                    if (possibleValues.size() < minLengthVector)
                    {
                        minLengthVector = possibleValues.size();
                        minV = possibleValues;
                        minI = i;
                        minJ = j;
                    }
                }
            }
        }

        if (minLengthVector != 10)
        {
            for(int i : minV)
            {
                board[minI][minJ] = (char)(i + 48);
                    
                solveSudokuRecursive(board, solved);
                    if (solved) 
                        break;
            
                board[minI][minJ] = '.';
            }
        }
        else
            solved = true;
    }
    
    void solveSudoku(vector<vector<char>>& board)
    {
        bool solved = false;
        solveSudokuRecursive(board, solved);
    }
};