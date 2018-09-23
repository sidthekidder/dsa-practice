// https://leetcode.com/problems/longest-increasing-subsequence/
// time complexity - O(n^2), space complexity - O(N)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int N = nums.size();
        if (N == 0) return 0;
        vector<int> dp(N);
        
        dp[0] = 1;
        for(int i = 1 ; i < N ; i++)
        {
            dp[i] = 1;
            for(int j = 0 ; j < i ; j++)
            {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        // now find the longest
        int maxElement = 0;
        for(int i = 0 ; i < N ; i++)
            maxElement = max(maxElement, dp[i]);

        return maxElement;
    }
};