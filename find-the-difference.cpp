// https://leetcode.com/problems/find-the-difference
// time complexity - O(N), space - O(1)

class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        int sum = 0;
        for(char ch : t)
            sum += (ch - 'a');
        for(char ch : s)
            sum -= (ch - 'a');
        return (char)(sum + 'a');
    }
};