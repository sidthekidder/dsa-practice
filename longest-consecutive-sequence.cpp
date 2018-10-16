// https://leetcode.com/problems/longest-consecutive-sequence
// time complexity - O(N), space complexity - O(N)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if (nums.size() == 0) 
            return 0;

        set<int> numbers;
        for(int i : nums)
            numbers.insert(i);

        int prev = -13117; 
        int count = 1, maxCount = 1;
        
        for(set<int>::iterator itr = numbers.begin() ; itr != numbers.end() ; itr++)
        {
            if (prev != -13117)
                if (*itr == prev+1)
                    maxCount = max(++count, maxCount);
                else
                    count = 1;
            prev = *itr;
        }

        return maxCount;
    }
};