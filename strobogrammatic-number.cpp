// https://leetcode.com/problems/strobogrammatic-number
// time complexity - O(N), space complexity - O(1)

class Solution {
public:
    bool stroboCheck(char ch1, char ch2)
    {
        if ((ch1 == '1' && ch2 == '1') || 
            (ch1 == '6' && ch2 == '9') || 
            (ch1 == '9' && ch2 == '6') || 
            (ch1 == '8' && ch2 == '8') || 
            (ch1 == '0' && ch2 == '0'))
            return true;
        else
            return false;
    }
    
    bool isStrobogrammatic(string num) 
    {
        // 0,1,8,6-9 allowed
        for(int i = 0, j = num.length() - 1 ; i <= j ; i++, j--)
            if (!stroboCheck(num[i], num[j]))
                return false;

        return true;
    }
};