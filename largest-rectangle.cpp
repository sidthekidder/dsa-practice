class Solution 
{
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int maxArea = 0;
        for(int i = 0 ; i < heights.size() ; i++)
        {
            int curHeight = heights[i];
            int left = i, right = i;
            
            while (left >= 0 && heights[left] >= curHeight)
                left--;
            left++;
            while (right < heights.size() && heights[right] >= curHeight)
                right++;
            right--;
            maxArea = max(maxArea, curHeight * (right - left + 1));
        }
        
        return maxArea;
    }
};