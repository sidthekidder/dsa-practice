// https://leetcode.com/problems/escape-the-ghosts
// time complexity - O(N), space complexity - O(1)

class Solution 
{
public:
    int dist(int x1, int y1, int x2, int y2)
    {
        return abs(y2 - y1) + abs(x2 - x1);
    }
    
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) 
    {
        int yourDist = dist(0, 0, target[0], target[1]);
        for(int i = 0 ; i < ghosts.size() ; i++)
        {
            int ghostDist = dist(ghosts[i][0], ghosts[i][1], target[0], target[1]);
            if (ghostDist <= yourDist)
                return false;
        }
        return true;
    }
};