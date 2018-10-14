// https://leetcode.com/problems/sqrtx
// time complexity - O(N)

class Solution {
public:
    int mySqrt(int x) {
        for(double i = 0 ; i <= x ; i++)
            if (i*i <= x && x < (i+1)*(i+1))
                return i;
        return 0;
    }
};