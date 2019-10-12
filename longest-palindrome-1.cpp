// https://leetcode.com/problems/longest-palindromic-substring
// time complexity - O(N^2), space complexity - O(N^2)

class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        // naive method - n^2
        // dp method - to check substring i,j - check if i+1,j-1 && s[i] == s[j]
        // create dp table
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = 0 ; i < n ; i++)
        {
            dp[i][i] = true;
            if (i + 1 < n && s[i] == s[i+1])
                dp[i][i+1] = true;
        }

        for(int i = n - 2 ; i >= 0 ; i--)
        {
            for(int j = i + 2 ; j < n ; j++)
            {
                dp[i][j] = (dp[i+1][j-1] && (s[i] == s[j]));
            }
        }
        
        // now find longest palin substring
        // find largest i,j which is true
        int maxLen = 0;
        string maxStr = "";
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i ; j < n ; j++)
            {
                if (dp[i][j] && j-i+1 > maxLen)
                {
                    maxLen = j-i+1;
                    maxStr = s.substr(i, j-i+1);
                }
            }
        }
        return maxStr;
    }
};