// https://leetcode.com/problems/3sum/
// time complexity - O(N^2), space complexity - O(1)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        // return an array of triplets - find all triplets
        // fix 1st pointer to leftmost and increment 2nd and decrement 3rd linearly - n^2 loop
        // whenever we increment lo/decrement hi, check for duplicates and 
        // keep incrementing/decrementing till no duplicates exist
        
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        for(int i = 0 ; i < nums.size() ; )
        {
            // perform linear search with 2 pointers at both ends
            int target = -nums[i];
            int lo = i + 1;
            int hi = nums.size() - 1;
            
            while (lo < hi)
            {
                if (target == nums[lo] + nums[hi])
                {
                    // found a triplet!
                    result.push_back({nums[i], nums[lo], nums[hi]});
                    lo++;
                    hi--;
                    
                    // removing duplicates for lo
                    while (lo < hi && nums[lo] == nums[lo-1]) lo++;
                    
                    // removing duplicates for hi
                    while (lo < hi && nums[hi] == nums[hi+1]) hi++;
                }
                else if (target > nums[lo] + nums[hi])
                {
                    lo++;
                    while (lo < hi && nums[lo-1] == nums[lo]) lo++;
                }
                else // target < nums[lo] + nums[hi]
                {
                    hi--;
                    while (hi > lo && nums[hi+1] == nums[hi]) hi--;
                }
            }
            i++;
            while (i < nums.size() && nums[i-1] == nums[i]) i++;
        }
        return result;
    }
};