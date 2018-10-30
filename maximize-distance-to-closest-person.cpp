// https://leetcode.com/problems/maximize-distance-to-closest-person
// time complexity - O(N), space complexity - O(2N)

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) 
    {
        // build 2 arrays - closest from left and from right
        // eg - [1,0,0,0,1,0,] = 
        // left_closest  = [0,1,2,3,0,1]
        // right_closest = [0,3,2,1,0,-1]
        
        vector<int> left_closest, right_closest;
        int closest = -99;
        for(int i = 0 ; i < seats.size() ; i++)
        {
            if (seats[i] == 1)
                closest = -1;
            left_closest.push_back(++closest);
        }
        closest = -99;
        for(int i = seats.size() - 1 ; i >= 0 ; i--)
        {
            if (seats[i] == 1)
                closest = -1;
            right_closest.push_back(++closest);
        }
        reverse(right_closest.begin(), right_closest.end());
        
        // loop through and find max min value
        int max_val = numeric_limits<int>::min();
        for(int i = 0 ; i < left_closest.size() ; i++)
            if (left_closest[i] < 0 || right_closest[i] < 0)
                max_val = max(max_val, max(left_closest[i], right_closest[i]));
            else
                max_val = max(max_val, min(left_closest[i], right_closest[i]));

        return max_val;
    }
};
