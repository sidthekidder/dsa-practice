// https://leetcode.com/problems/perfect-squares
// time complexity - O(N^2), space complexity - O(N)

class Solution {
public:
    int findMink(int n, vector<int>& value)
    {
        if (n <= 3) 
            return n;
        if (value[n] != numeric_limits<int>::max()) 
            return value[n];
        
        int q = numeric_limits<int>::max();
        for(int x = 1 ; x*x <= n ; x++)
            q = min(q, 1 + findMink(n - x*x, value));

        value[n] = q;
        return value[n];
    }
    
    int numSquares(int n) 
    {
        vector<int> value(n+1, numeric_limits<int>::max());
        return findMink(n, value);
    }
};