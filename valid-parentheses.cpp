// https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s)
    {
        stack<char> stk;
        map<char, char> opposite = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
        for(int i = 0 ; i < s.length() ; i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                stk.push(s[i]);
            }
            else if (s[i] == ']' || s[i] == '}' || s[i] == ')')
            {
                if (stk.empty()) return false;
                if (opposite[stk.top()] != s[i]) return false;
                stk.pop();
            }
        }
        if (!stk.empty()) 
            return false;
        return true;
    }
};