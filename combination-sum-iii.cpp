// https://leetcode.com/problems/combination-sum-iii
// time complexity - O(N!), space complexity - O(N!)

class Solution 
{
public:
    void backtrack(int curSum, int idx, vector<int> curList, set<vector<int>>& finalresult, int& target, vector<bool> visited)
    {
        if (curSum == target)
        {
            finalresult.insert(curList);
            return;
        }
        
        for(int i = idx ; i <= 9 ; i++)
        {
            if (i + curSum > target) return;
            if (visited[i]) continue;

            curList.push_back(i);
            visited[i] = true;
            backtrack(curSum + i, i, curList, finalresult, target, visited);
            curList.pop_back();
            visited[i] = false;
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int target) 
    {
        set<vector<int>> finalresult;
        vector<bool> visited(10, false);
        backtrack(0, 1, vector<int>(), finalresult, target, visited);
        
        vector<vector<int>> res;
        for(auto itr =finalresult.begin() ; itr != finalresult.end() ; itr++)
        {
            if ((*itr).size() == k)
                res.push_back(*itr);
        }
        return res;
    }
};