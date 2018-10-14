// https://leetcode.com/problems/nested-list-weight-sum-ii/
// time complexity - O(N), space complexity - O(max depth)

class Solution {
public:
    int getMaxDepth(vector<NestedInteger> ni, int curDepth)
    {
        int maxDepth = curDepth;
        for(int i = 0 ; i < ni.size() ; i++)
            if (!ni[i].isInteger())
                maxDepth = max(maxDepth, getMaxDepth(ni[i].getList(), curDepth + 1));
        
        return maxDepth;
    }
    
    int getSum(vector<NestedInteger> ni, int curDepth)
    {
        int sum = 0;
        for(int i = 0 ; i < ni.size() ; i++)
            if (ni[i].isInteger())
                sum += curDepth * ni[i].getInteger();
            else
                sum += getSum(ni[i].getList(), curDepth-1);
        
        return sum;
    }
    
    int depthSumInverse(vector<NestedInteger>& nestedList) 
    {
        int maxDepth = getMaxDepth(nestedList, 1);
        return getSum(nestedList, maxDepth);
    }
};