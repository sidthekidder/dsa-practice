// https://leetcode.com/problems/circular-array-loop/
// time complexity - O(N), space complexity - O(1)

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) 
    {
        // pos/neg array
        // output - yes if loop
        // loop must have more than 1 element
        // loop must be forward or backward - cant change direction
        // start checking from each index, follow the indexes
        // if direction changes, return false
        // if original index is crossed, return false
        // eg [-1,2]
        for(int i = 0 ; i < nums.size() ; i++)
        {
            int original_idx = i;
            int cur_idx = nums[i];
            bool crossed_flag = false;
            bool direction = (nums[i] > 0)? true : false;
            while ((!crossed_flag && cur_idx > original_idx) || (crossed_flag && cur_idx <= original_idx))
            {
                if (cur_idx >= nums.size())
                    cur_idx = cur_idx % nums.size(), crossed_flag = true;
                else if (cur_idx < 0)
                    cur_idx += nums.size();

                if (cur_idx == original_idx)
                    return true;
                if ((nums[cur_idx] < 0 && direction) || (nums[cur_idx] > 0 && !direction))
                    break;
                
                cur_idx = cur_idx + nums[cur_idx];
            }
        }
        return false;
    }
};