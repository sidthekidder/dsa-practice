class Solution {
public:
    int rob(vector<int>& nums)
    {
        int dp[nums.size() + 1];
        for(int i = 0 ; i < nums.size() + 1 ; i++) dp[i] = -1;
        return maxMoney(nums, nums.size() - 1, dp);
    }
    
    int maxMoney(vector<int> &nums, int curIdx, int dp[])
    {
        if (curIdx < 0) return 0;
        if (dp[curIdx] >= 0) return dp[curIdx];
        
        dp[curIdx] = max(maxMoney(nums, curIdx - 2, dp) + nums[curIdx], maxMoney(nums, curIdx - 1, dp));
        
        return dp[curIdx];
    }
};

