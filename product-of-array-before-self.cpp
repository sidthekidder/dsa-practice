// https://leetcode.com/problems/product-of-array-except-self
// time complexity - O(n), space complexity - O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        // input - array of n integers
        // output - array where output[i] = product of all elements except nums[i]
        // without division in O(n)
        
        // build 2 arrays prefix and suffix product arrays
        vector<int> result, prefix, suffix;
        int len = nums.size();
        int prod = 1;
        for(int i = 0 ; i < len ; i++)
        {
            prod *= nums[i];
            prefix.push_back(prod);
        }
        prod = 1;
        for(int i = len - 1 ; i >= 0 ; i--)
        {
            prod *= nums[i];
            suffix.push_back(prod);
        }
        reverse(suffix.begin(), suffix.end());
        
        // now build the final array
        for(int i = 0 ; i < len ; i++)
        {
            int ele = ((i-1 >= 0)? prefix[i-1] : 1) * ((i+1 < len)? suffix[i+1] : 1);
            result.push_back(ele);
        }
        return result;
    }
};