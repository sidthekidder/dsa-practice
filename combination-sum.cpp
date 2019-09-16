// https://leetcode.com/problems/combination-sum
// time complexity - O(N!), space complexity - O(N!)

class Solution 
{
public:
    void backtrack(vector<int>& candidates, int curSum, vector<int> curList, int& target, vector<vector<int>>& result, int idx)
    {
        if (curSum == target)
        {
            result.push_back(curList);
            return;
        }
        for(int i = idx ; i < candidates.size() ; i++)
        {
            if (candidates[i] + curSum > target) return;
            curList.push_back(candidates[i]);
            backtrack(candidates, curSum + candidates[i], curList, target, result, i);
            curList.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        // return list of lists
        // call recursive function, with index 0, and current list empty
        // base case - last index reached, insert current list in final result
        // for current index element, if curSum+element < total, insert and recall
        // also recall
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> curList;
        backtrack(candidates, 0, curList, target, result, 0);
        return result;
    }
};