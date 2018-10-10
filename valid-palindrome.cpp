// https://leetcode.com/problems/valid-palindrome
// time complexity - O(n)

class Solution {
public:
    bool isPalindrome(string s) 
    {
        if (s.length() == 0) return true;
        int i = 0, j = s.length() - 1;
        while (i < j)
        {
            // increment i, decrement j while they are not alphanumeric
            while (i < j && !((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')))
                i++;
            while (i < j && !((s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= 'a' && s[j] <= 'z') || (s[j] >= '0' && s[j] <= '9')))
                j--;

            if (toupper(s[i]) != toupper(s[j]))
                return false;
            // a
            i++;
            j--;
        }
        return true;
    }
};