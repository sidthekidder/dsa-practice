// https://leetcode.com/problems/hamming-distance

class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        while (x != 0 || y != 0)
        {
            int t1 = x%2;
            int t2 = y%2;
            if (t1 != t2)
                count++;
            x = x >> 1;
            y = y >> 1;
        }
        return count;
    }
};