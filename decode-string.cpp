// https://leetcode.com/problems/decode-string/
// time complexity - O(N), space complexity - O(1)

class Solution {
public:
    string decodeRecur(string s, int idx, int multiply)
    {
        string res = "";
        for(int i = 0 ; i < s.length() ; i++)
        {
            if (s[i] == '[')
            {
                // get multiplier by traversing through result till now and picking out numbers        
                string newres = "", multiply_string = "";
                for(char ch : res)
                    if (ch >= '0' && ch <= '9')
                        multiply_string += ch;
                    else
                        newres += ch;
                int multiplier = stoi(multiply_string);
                // remove the numbers from result till now
                res = newres;

                string temp = "";
                int openBracket = 1;
                for (int j = i+1 ; j < s.length() ; j++)
                {
                    if (s[j] == '[')
                        openBracket++;
                    else if (s[j] == ']')
                        openBracket--;
                    if (openBracket == 0) // finished, call recur on inner string and break;
                    {
                        res += decodeRecur(temp, 0, multiplier);
                        i = j; // update i to char after closing bracket
                        break;
                    }
                    else
                        temp += s[j];
                }
            }
            else
                res += s[i];
        }
        
        string final_result = "";
        while (multiply--)
            final_result += res;
        return final_result;
    }
    
    string decodeString(string s) 
    {
        // 2[abc]3[cd]ef
        // start from 2
        // s = "abcabccdcdcdef"
        // open = 0
        // temp = "cd" decodeRecur(s, multiply) where multiple = "left side go till there is a number"

        return decodeRecur(s, 0, 1);
    }
};