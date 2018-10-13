// https://leetcode.com/problems/valid-palindrome-ii/
// time complexity - O(n^2), space complexity - O(n^2) (call stack)

class Solution {
public:
    bool recursiveCheck(string &s, int i, int j, int deletesLeft)
    {
        if (i >= j)
            return true;
        
        if (s[i] != s[j])
            return (deletesLeft > 0) && (recursiveCheck(s, i+1, j, deletesLeft-1) || recursiveCheck(s, i, j-1, deletesLeft-1));
        else
            return recursiveCheck(s, i+1, j-1, deletesLeft);
    }
    
    bool validPalindrome(string s) 
    {
        return recursiveCheck(s, 0, s.length() - 1, 1);
    }
};