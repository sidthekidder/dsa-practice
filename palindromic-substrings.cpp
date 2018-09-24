// https://leetcode.com/problems/palindromic-substrings

class Solution {
public:
    bool isPalindrome(string s)
    {
        int i = 0, j = s.length() - 1;
        while (i < j )
        {
            if (s[i] != s[j]) 
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    int countSubstrings(string s)
    {
        int len = s.length();
        int sum = 0;
        // loop over n^2 strings - naive
        for(int i = 0 ; i < len ; i++)
        {
            for(int j = i; j < len ; j++)
            {
                string subs = s.substr(i, j - i + 1);
                if (isPalindrome(subs)) sum++;
            }
        }
        return sum;
    }
};