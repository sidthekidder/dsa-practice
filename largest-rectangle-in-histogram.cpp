// https://leetcode.com/problems/largest-rectangle-in-histogram
// time complexity - O(NlogN), space complexity - O(N) (recursion stack)

class Solution {
public:
    int bestArea(vector<int>& heights, int lo, int hi)
    {
        if (lo > hi)
            return 0;
        if (lo == hi)
            return heights[lo];
        
        int min_idx = lo;
        for(int i = lo ; i <= hi ; i++)
            if (heights[min_idx] > heights[i])
                min_idx = i;
        
        return max(heights[min_idx] * (hi - lo + 1), max(bestArea(heights, min_idx + 1, hi), bestArea(heights, lo, min_idx - 1)));
    }

    int largestRectangleArea(vector<int>& heights) 
    {
        return bestArea(heights, 0, heights.size()-1);
    }
};