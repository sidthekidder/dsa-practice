// https://leetcode.com/problems/k-closest-points-to-origin/submissions/
// time complexity - O(N log N), space complexity - O(N)

class Solution 
{
public:
    static bool comparator(pair<double, vector<int>> p1, pair<double, vector<int>> p2)
    {
        return p1.first > p2.first;
    }
    
    double get_dist(int x, int y)
    {
        return sqrt(x*x + y*y);
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) 
    {
        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, function<bool(pair<double, vector<int>>, pair<double, vector<int>>)>> pq(comparator);

        for(vector<int> point : points)
        {
            double dist = get_dist(point[0], point[1]);
            pq.push({dist, point});
        }
        
        vector<vector<int>> result;
        while (K > 0)
        {
            K--;
            auto ele = pq.top();
            result.push_back(ele.second);
            pq.pop();
        }
        return result;
    }
};