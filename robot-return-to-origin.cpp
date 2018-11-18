// https://leetcode.com/problems/robot-return-to-origin/
// time complexity - O(N), space complexity - O(1)

class Solution {
public:
    bool judgeCircle(string moves) 
    {
        int h = 0, v = 0;
        for(char ch : moves)
        {
            if (ch == 'L')
                h--;
            else if (ch == 'R')
                h++;
            else if (ch == 'U')
                v++;
            else if (ch == 'D')
                v--;
        }
        return ((h == 0) && (v == 0));
    }
};