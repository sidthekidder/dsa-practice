// https://leetcode.com/problems/maximum-size-subarray-sum-equals-k
// time complexity - O(N), space complexity - O(1)

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k)
    {
        if (nums.size() == 0) return 0;
        // input - unsorted array nums, target k
        // output - max length of subarray
        
        // sum[i] + sum[j] = k, so sum[j] - k = sum[i]
        // now find max j-i such that sum[j] - k is in mapping
        // keep cumulative sum in cum_sum variable
        // dont need to store previous 
        unordered_map<int, int> mapping;
        int cum_sum = 0;
        int max_len = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            cum_sum += nums[i];
            if (cum_sum == k)
                max_len = i+1;
            else if (mapping.find(cum_sum - k) != mapping.end())
                max_len = max(max_len, i - mapping[cum_sum - k]);
            if (mapping.find(cum_sum) == mapping.end())
                mapping[cum_sum] = i;
        }
        return max_len;
    }
};
