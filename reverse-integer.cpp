// https://leetcode.com/problems/reverse-integer/
// time complexity - O(log x), space complexity - O(1)

class Solution {
public:
    int reverse(int x) 
    {
        bool neg = false;
        if (x < 0)
        {
            neg = true;
            x *= -1;
        }
        
        int r = 0, prevr = 0;
        while (x > 0)
        {
            r = r*10 + x%10;
            
            if ((r - x%10)/10 != prevr) // overflow
                return 0;
            
            prevr = r;
            x /= 10;
        }
        
        if (neg)
            r *= -1;
        
        return r;
    }
};