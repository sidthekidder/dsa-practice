// https://leetcode.com/problems/subsets/
// time complexity - O(n.2^n)

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // use bitmasking to get the power set
        vector<vector<int>> result;
        
        int n = nums.size();
        for(int i = 0 ; i < pow(2, n) ; i++)
        {
            vector<int> tempResult;
            for(int j = 0 ; j < n ; j++)
                if (i & (1 << j))
                    tempResult.push_back(nums[j]);
            
            result.push_back(tempResult);
        }
        
        return result;
    }
};