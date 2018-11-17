// https://leetcode.com/problems/flipping-an-image/
// time complexity - O(N^2), space complexity - O(1)

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) 
    {
        for(int i = 0 ; i < A.size() ; i++)
        {
            int a = 0, b = A[0].size() - 1;
            while (a <= b)
            {
                int temp = A[i][a];
                A[i][a] = !A[i][b];
                A[i][b] = !temp;
                a++;
                b--;
            }
        }
        return A;
    }
};