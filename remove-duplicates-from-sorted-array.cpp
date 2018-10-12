// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// time complexity - O(n)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int cur = 0, head = 1;
        if (nums.size() <= 1) return nums.size();
        
        for ( ; head < nums.size() ; head++)
            if (nums[cur] != nums[head])
                nums[++cur] = nums[head];

        return cur+1;
    }
};