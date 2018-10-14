// https://leetcode.com/problems/flood-fill/
// time complexity - O(N - size of grid), space complexity - O(N)

class Solution {
public:
    void dfsFloodFillHelper(vector<vector<int>>& image, int sr, int sc, int &newColor, int originalColor, bool visited[51][51])
    {
        visited[sr][sc] = true;
        image[sr][sc] = newColor;
        if (sr + 1 < image.size() && image[sr+1][sc] == originalColor && !visited[sr+1][sc])
            dfsFloodFillHelper(image, sr+1, sc, newColor, originalColor, visited);
        
        if (sr - 1 >= 0 && image[sr-1][sc] == originalColor && !visited[sr-1][sc])
            dfsFloodFillHelper(image, sr-1, sc, newColor, originalColor, visited);
        
        if (sc + 1 < image[0].size() && image[sr][sc+1] == originalColor && !visited[sr][sc+1])
            dfsFloodFillHelper(image, sr, sc+1, newColor, originalColor, visited);
        
        if (sc - 1 >= 0 && image[sr][sc-1] == originalColor && !visited[sr][sc-1])
            dfsFloodFillHelper(image, sr, sc-1, newColor, originalColor, visited);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        bool visited[51][51] = {false};
        dfsFloodFillHelper(image, sr, sc, newColor, image[sr][sc], visited);
        return image;
    }
};