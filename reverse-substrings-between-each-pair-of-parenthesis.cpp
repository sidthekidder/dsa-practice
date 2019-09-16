// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
// time complexity - O(n^2), space complexity - O(n)

class Solution {
    public:
    string reverseParentheses1(string s)
    {
    	// get first and last index of open/close bracket
        // if none found, reverse string and return
        // send substring inside to reverseParentheses function
        // return reverse(left-bracket + result + right-bracket)

        int first_idx = s.find("(");
        if (first_idx == string::npos)
        {
            reverse(s.begin(), s.end());
            return s;
        }
        
        // run loop to find last idx
        int last_idx;
        int openBrackets = 1;
        for(int i = first_idx + 1 ; i < s.length() ; i++)
    	{
    		if (s[i] == ')' && openBrackets == 1)
    		{
    			last_idx = i;
    			break;
    		}
    		else if (s[i] == ')')
    			openBrackets--;
    		else if (s[i] == '(')
    			openBrackets++;
    	}
        
        string firstpart = s.substr(0, first_idx);
        
        string lastpart = s.substr(last_idx + 1, s.length() - last_idx + 1);
        
        string substr = s.substr(first_idx+1, last_idx - first_idx - 1); // part containing brackets
        string recursivepart = reverseParentheses1(substr);
        
        // form new string
        string newstring = firstpart + recursivepart + reverseParentheses(lastpart);
        reverse(newstring.begin(), newstring.end());
        
        // check if still remains
        if (newstring.find("(") != string::npos)
        {
        	return reverseParentheses1(newstring);
        }
        
        return newstring;
    }
    string reverseParentheses(string s)
    {
    	// get first and last index of open/close bracket
        // if none found, reverse string and return
        // send substring inside to reverseParentheses function
        // return reverse(left-bracket + result + right-bracket)
        int first_idx = s.find("(");
        if (first_idx == string::npos)
        {
            return s;
        }
        
        // run loop to find last idx
        int last_idx;
        int openBrackets = 1;
        for(int i = first_idx + 1 ; i < s.length() ; i++)
    	{
    		if (s[i] == ')' && openBrackets == 1)
    		{
    			last_idx = i;
    			break;
    		}
    		else if (s[i] == ')')
    			openBrackets--;
    		else if (s[i] == '(')
    			openBrackets++;
    	}
        
        string firstpart = s.substr(0, first_idx);
        
        string lastpart = s.substr(last_idx + 1, s.length() - last_idx + 1);
        
        string substr = s.substr(first_idx+1, last_idx - first_idx - 1); // part containing brackets
        string recursivepart = reverseParentheses1(substr);
        
        // form new string
        string newstring = firstpart + recursivepart + reverseParentheses(lastpart);
        
        // check if still remains
        if (newstring.find("(") != string::npos)
        {
        	return reverseParentheses(newstring);
        }
        
        return newstring;
    }
};