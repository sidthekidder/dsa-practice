// https://leetcode.com/problems/move-zeroes
// time complexity - O(N)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cur = 0, i = 0;
        for( ; i < nums.size() ; i++)
            if (nums[i] != 0)
                nums[cur++] = nums[i];

        while (cur < i)
            nums[cur++] = 0;
    }
};