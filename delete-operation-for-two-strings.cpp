// https://leetcode.com/problems/delete-operation-for-two-strings
// time complexity - O(M*N), space complexity - O(MN)

class Solution {
public:
    int minDist(string word1, string word2, int i, int j, vector<vector<int>>& dp)
    {
        if (i == word1.length() && j == word2.length())
            return 0;
        else if (i == word1.length())
            return word2.length() - j;
        else if (j == word2.length())
            return word1.length() - i;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        if (word1[i] == word2[j])
            return dp[i][j] = minDist(word1, word2, i + 1, j + 1, dp);
        else
            return dp[i][j] = min(minDist(word1, word2, i + 1, j, dp), minDist(word1, word2, i, j + 1, dp)) + 1;
    }
    
    int minDistance(string word1, string word2) 
    {
        // input - 2 words
        // output - min number of steps to convert word1 to word2
        // sea -> ea -> eat
        // delete option possible
        vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, -1));
        return minDist(word1, word2, 0, 0, dp);
    }
};