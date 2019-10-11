// https://leetcode.com/problems/generate-parentheses
// time complexity - O(4^n / root(n)), space complexity - O(4^n / root(n))

class Solution {
public:
    void recur(vector<string>& res, int n, int open, string cur)
    {
        if (n == 0)
        {
            if (open == 0)
                res.push_back(cur);
            return;
        }
        if (open < n)
            recur(res, n, open+1, cur+"(");
        if (open > 0)
            recur(res, n-1, open-1, cur+")");
    }
    
    vector<string> generateParenthesis(int n) 
    {
        vector<string> res;
        recur(res, n, 0, "");
        return res;
    }
};