// https://leetcode.com/problems/generate-parentheses/
// time complexity - O(N*catalan(N)), space - O(N*catalan(N))

class Solution {
public:
    bool is_valid(string str)
    {
        int brackets = 0;
        for(char ch : str)
        {
            if (ch == '(')
                brackets++;
            else if (ch == ')')
                brackets--;
            if (brackets < 0)
                return false;
        }
        return (brackets == 0)? true : false;
    }
    
    void recurHelper(unordered_set<string>& result, string cur_string, int total, int open)
    {
        if (total == 0 && open == 0)
        {
            if (is_valid(cur_string))
                result.insert(cur_string);
        }
        else if (total == 0 && open != 0)
        {
            recurHelper(result, cur_string + ")", total, open - 1);
        }
        else
        {
            recurHelper(result, cur_string + "()", total - 1, 0);
            recurHelper(result, cur_string + "(", total - 1, open + 1);
            if (open >= 1)
                recurHelper(result, cur_string + ")", total, open - 1);
        }
    }

    vector<string> generateParenthesis(int n) 
    {
        unordered_set<string> result;
        recurHelper(result, "", n, 0);
        vector<string> res(result.begin(), result.end());
        return res;
    }
};