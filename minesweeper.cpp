// https://leetcode.com/problems/minesweeper/
// time complexity - O(N), space complexity - O(1)

class Solution {
public:
    int validMine(vector<vector<char>>& board, int x, int y)
    {
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
            return 0;
        if (board[x][y] == 'M') 
            return 1;
        else
            return 0;
    }
    
    void playGame(vector<vector<char>>& board, int x, int y, int dir[8][2])
    {
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] != 'E')
            return;
        
        int count = 0;
        for(int i = 0 ; i < 8 ; i++)
            count += validMine(board, x + dir[i][0], y + dir[i][1]);

        if (count == 0)
        {
            board[x][y] = 'B';
            for(int i = 0 ; i < 8 ; i++)
                playGame(board, x + dir[i][0], y + dir[i][1], dir);
        }
        else
            board[x][y] = (char)(count + 48);
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) 
    {
        int x = click[0], y = click[1];
        int dir[8][2] = {{1, 0}, {1, 1}, {1, -1}, {-1, 0}, {-1, 1}, {-1, -1}, {0, -1}, {0, 1}};
        
        if (board[x][y] == 'M')
            board[x][y] = 'X';
        else
            playGame(board, x, y, dir);

        return board;
    }
};