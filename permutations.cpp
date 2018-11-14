// https://leetcode.com/problems/permutations/
// time complexity - O(N^N), space complexity - O(1)

class Solution {
public:
    void get_permutations(vector<int>& nums, int idx, vector<vector<int>>& result)
    {
        if (idx == nums.size())
        {
            result.push_back(nums);
            return;
        }

        for(int i = idx ; i < nums.size() ; i++)
        {
            int tmp = nums[idx];
            nums[idx] = nums[i];
            nums[i] = tmp;
            
            get_permutations(nums, idx + 1, result);
            
            nums[i] = nums[idx];
            nums[idx] = tmp;
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> result;
        get_permutations(nums, 0, result);
        return result;
    }
};