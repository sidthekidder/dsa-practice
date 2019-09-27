// https://leetcode.com/problems/interval-list-intersections
// time complexity - O(N), space complexity - O(1)

class Solution 
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) 
    {
        // given 2 lists of closed intervals, return intersection of these 2 lists
        
        int i = 0, j = 0;
        vector<vector<int>> res;
        while (i < A.size() && j < B.size())
        {
            if (A[i][0] <= B[j][1] && B[j][0] <= A[i][1])
            {
                res.push_back({max(A[i][0], B[j][0]), min(A[i][1], B[j][1])});
            }
            // move the pointer forward who's end time is lesser
            if (A[i][1] <= B[j][1])
                i++;
            else
                j++;
        }
        return res;
    }
};