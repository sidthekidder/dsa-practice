// https://leetcode.com/problems/the-maze/
// time complexity - O(N), space complexity - O(N)

class Solution {
public:
    bool isPathPossible(vector<vector<int>>& maze, int i, int j, int &fi, int &fj, char dir, bool visited[101][101])
    {
        if (dir == 'r')
        {
            // keep going right
            while (j < maze[0].size() && maze[i][j] != 1) 
                j++;
            j--;
        }
        else if (dir == 'l')
        {
            // keep going left
            while (j >= 0 && maze[i][j] != 1) 
                j--;
            j++;
        }
        else if (dir == 'u')
        {
            // keep going up
            while (i >= 0 && maze[i][j] != 1) 
                i--;
            i++;
        }
        else if (dir == 'd')
        {
            // keep going down
            while (i < maze.size() && maze[i][j] != 1) 
                i++;
            i--;
        }
        // if we reached the destination
        if (i == fi && j == fj) return true;

        // keep searching in the other 3 directions
        if (visited[i][j])
            return false;
        visited[i][j] = true;

        return (((dir == 'u') ? false : isPathPossible(maze, i, j, fi, fj, 'u', visited)) ||
                ((dir == 'd') ? false : isPathPossible(maze, i, j, fi, fj, 'd', visited)) ||
                ((dir == 'l') ? false : isPathPossible(maze, i, j, fi, fj, 'l', visited)) ||
                ((dir == 'r') ? false : isPathPossible(maze, i, j, fi, fj, 'r', visited)));
    }
    
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) 
    {
        bool visited[101][101] = {false};
        return isPathPossible(maze, start[0], start[1], destination[0], destination[1], 'r', visited) ||
                isPathPossible(maze, start[0], start[1], destination[0], destination[1], 'u', visited) ||
                isPathPossible(maze, start[0], start[1], destination[0], destination[1], 'd', visited) ||
                isPathPossible(maze, start[0], start[1], destination[0], destination[1], 'l', visited);
    }
};