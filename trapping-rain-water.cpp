// https://leetcode.com/problems/trapping-rain-water/
// time complexity - O(N)

class Solution {
public:
    int trap(vector<int>& height) 
    {
        int len = height.size();
        vector<int> leftPrefix(len), rightPrefix(len);
        if (len == 0) return 0;
        
        leftPrefix[0] = height[0];
        for(int i = 1 ; i < len ; i++)
            leftPrefix[i] = max(leftPrefix[i-1], height[i]);
        
        rightPrefix[len-1] = height[len-1];
        for(int i = len - 2 ; i >= 0 ; i--)
            rightPrefix[i] = max(rightPrefix[i+1], height[i]);

        int total = 0;
        for(int i = 1 ; i < len - 1 ; i++)
            total += min(leftPrefix[i], rightPrefix[i]) - height[i];

        return total;
    }
};