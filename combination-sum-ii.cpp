// https://leetcode.com/problems/combination-sum
// time complexity - O(N!), space complexity - O(N!)

class Solution 
{
public:
    void backtrack(vector<int>& candidates, int curSum, int idx, vector<int> curList, set<vector<int>>& finalresult, int& target, vector<bool> visited)
    {
        if (curSum == target)
        {
            finalresult.insert(curList);
            return;
        }
        
        for(int i = idx ; i < candidates.size() ; i++)
        {
            if (candidates[i] + curSum > target) return;
            // if (visited[i]) continue;
            if (i > 0 && i > idx && curList[i])

            curList.push_back(candidates[i]);
            // visited[i] = true;
            backtrack(candidates, curSum + candidates[i], i, curList, finalresult, target, visited);
            curList.pop_back();
            // visited[i] = false;
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        set<vector<int>> finalresult;
        vector<bool> visited(candidates.size(), false);
        backtrack(candidates, 0, 0, vector<int>(), finalresult, target, visited);
        vector<vector<int>> res(finalresult.begin(), finalresult.end());
        return res;
    }
};