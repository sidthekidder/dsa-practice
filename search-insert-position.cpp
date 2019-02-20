// https://leetcode.com/problems/search-insert-position
// time complexity - O(log N), space complexity - O(1)

class Solution 
{
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo)/2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                hi = mid - 1;
            else if (nums[mid] < target)
                lo = mid + 1;
        }
        if (lo > hi)
            return lo;
        else
            return hi;
    }
};