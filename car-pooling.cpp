// https://leetcode.com/problems/car-pooling/
// time complexity - O(N^2), space complexity - O(N)

class Solution 
{
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        // input - list of trips
        // return true or not
        
        auto cmp = [](vector<int> v1, vector<int> v2)
        {
            return v1[1] > v2[1];
        };
        
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        
        // also use a map from end time -> no of passengers dropped off
        map<int, int> dropoff;
        
        for(auto trip : trips)
        {
            pq.push(trip);
            dropoff[trip[2]] += trip[0];
        }
        
        int cur = 0;
        int prev_stop;
        while (!pq.empty())
        {
            vector<int> ele = pq.top();
            pq.pop();
            
            // remove all passengers till current stop
            for(int i = 1 ; i <= ele[1] ; i++)
            {
                if (dropoff.count(i) > 0)
                {
                    cur -= dropoff[i];
                    dropoff[i] = 0;
                }
            }
            
            // add new passengers
            cur += ele[0];
            
            // check for cur overflow
            if (cur > capacity)
                return false;
        }
        return true;
    }
};