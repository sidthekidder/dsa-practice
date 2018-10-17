// https://leetcode.com/problems/edit-distance
// time complexity - O(MN), time complexity - O(MN)

class Solution {
public:
    int minDist(string word1, string word2, int i1, int i2, vector<vector<int>>& dp)
    {
        if (i1 == word1.size() && i2 == word2.size()) // reached the end of both strings
            return 0;
        else if (i1 == word1.size()) // reached the end of word1 = (word2.size - i2) transformations needed
            return word2.size() - i2;
        else if (i2 == word2.size()) // reached the end of word2 = (word1.size - i1) transformations needed
            return word1.size() - i1;
        
        if (dp[i1][i2] != -1)
            return dp[i1][i2];
        
        if (word1[i1] == word2[i2])
            dp[i1][i2] = minDist(word1, word2, i1+1, i2+1, dp);
        else
            dp[i1][i2] = min(minDist(word1, word2, i1+1, i2+1, dp),
                         min(minDist(word1, word2, i1+1, i2, dp), 
                             minDist(word1, word2, i1, i2+1, dp))) + 1; // 1 op for either delete 1/2 or transform
        return dp[i1][i2];
    }
    
    int minDistance(string word1, string word2) 
    {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, -1));
        return minDist(word1, word2, 0, 0, dp);
    }
};