// https://leetcode.com/problems/word-search
// time complexity - O(M*N*wordlen), space complexity - O(M*N)

class Solution {
public:
    bool check_visited(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, string& word, int idx)
    {
        if (idx == word.length())
            return true;
        if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0)
            return false;
        if (idx > word.length())
            return false;
        if (!visited[i][j] && word[idx] == board[i][j])
        {
            visited[i][j] = true;
            if (check_visited(board, visited, i+1, j, word, idx+1))
                return true;
            if (check_visited(board, visited, i, j+1, word, idx+1))
                return true;
            if (check_visited(board, visited, i-1, j, word, idx+1))
                return true;
            if (check_visited(board, visited, i, j-1, word, idx+1))
                return true;
            visited[i][j] = false;
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) 
    {
        // input - word and grid
        // loop through every starting point and check in all directions
        // exponential approach
        for(int i = 0 ; i < board.size() ; i++)
        {
            for(int j = 0 ; j < board[i].size() ; j++)
            {
                if (board[i][j] == word[0])
                {
                    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
                    if (check_visited(board, visited, i, j, word, 0))
                        return true;
                }
            }
        }
        return false;
    }
};