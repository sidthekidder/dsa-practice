// https://leetcode.com/problems/nested-list-weight-sum/
// time complexity - O(N), space complexity - O(max depth)

class Solution {
public:
    int getSum(vector<NestedInteger> ni, int curDepth)
    {
        int sum = 0;
        for(int i = 0 ; i < ni.size() ; i++)
            if (ni[i].isInteger())
                sum += curDepth * ni[i].getInteger();
            else
                sum += getSum(ni[i].getList(), curDepth + 1);

        return sum;
    }
    
    int depthSum(vector<NestedInteger>& nestedList) 
    {
        return getSum(nestedList, 1);
    }
};