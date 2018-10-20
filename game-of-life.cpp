// https://leetcode.com/problems/game-of-life/
// time complexity - O(N^2), space complexity - O(1)

class Solution {
public:
    int get_board(int i, int j, vector<vector<int>>& board)
    {
        if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0) return 0;
        
        if (board[i][j] == 1) return 1;
        else if (board[i][j] == -2) return 0;
        else if (board[i][j] == -1) return 1;
        else if (board[i][j] == 0) return 0;
    }
    
    int get_neighbors(vector<vector<int>>& board, int i, int j)
    {
        int count = 0;
        int dir[8][2] = {{1,0}, {0,1}, {1,1}, {-1,0}, {0,-1}, {-1,-1}, {1,-1}, {-1,1}};
        for(int a = 0 ; a < 8 ; a++)
            count += get_board(i+dir[a][0], j + dir[a][1], board);
        return count;
    }
    
    void gameOfLife(vector<vector<int>>& board) 
    {
        // let 0 = dead in both states, 1 = alive in both states
        // -1 = previously alive, dead in next state
        // -2 = previously dead, alive in next state
        for(int i = 0 ; i < board.size() ; i++)
        {
            for(int j = 0 ; j < board[0].size() ; j++)
            {
                int neighbors = get_neighbors(board, i, j);
                if (board[i][j] == 1) // alive
                {
                    if (neighbors < 2) // dies
                        board[i][j] = -1;
                    else if (neighbors > 3) // dies
                        board[i][j] = -1;
                }
                else if (board[i][j] == 0) // dead
                {
                    if (neighbors == 3) // lives
                        board[i][j] = -2;
                }
            }
        }
        // update board - change -1 and -2 to their corresponding actual meanings
        for(int i = 0 ; i < board.size() ; i++)
        {
            for(int j = 0 ; j < board[0].size() ; j++)
            {
                if (board[i][j] == -1)
                    board[i][j] = 0;
                else if (board[i][j] == -2)
                    board[i][j] = 1;
            }
        }
    }
};