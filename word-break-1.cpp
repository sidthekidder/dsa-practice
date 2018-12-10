// https://leetcode.com/problems/word-break/
// time complexity - O(N^2), space complexity - O(N)

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        // input - string and dict of words
        // iterate through string recursively
        vector<int> dp(s.length() + 1, 0);
        dp[0] = 1;
        
        for(int i = 1 ; i <= s.length() ; i++)
        {
            for(int j = 0 ; j < i ; j++)
            {
                string str = s.substr(j, i - j);
                if (dp[j] && find(wordDict.begin(), wordDict.end(), str) != wordDict.end())
                {
                    dp[i] = 1;
                    break;
                }
            }
        }
        
        return dp[s.length()];
    }
};