// O(N^2) solution
// O(N) for maxheap remove operation, log N for insert, and O(N) for iterating over points

template<typename T>
class custom_priority_queue : public std::priority_queue<T, std::vector<T>>
{
  public:

      bool remove(const T& value) {
        auto it = std::find(this->c.begin(), this->c.end(), value);
            if (it != this->c.end()) {
                this->c.erase(it);
                std::make_heap(this->c.begin(), this->c.end(), this->comp);
                return true;
           }
           else {
            return false;
           }
      }
};


class Solution {
public:
    
    static bool bpointCompare(const pair<pair<int, int>, bool> &p1, const pair<pair<int, int>, bool> &p2)
	{
        if (p1.first.first == p2.first.first) // x coordinates are same for both
        {
            // order according to start/end points
            if (p1.second && p2.second) // both are start points - higher one should come first
            {
                return p1.first.second > p2.first.second;
            }
            else if (p1.second && !p2.second) // p1 is start and p2 is end - p1 should come first
            {
                return true;
            }
            else if (!p1.second && p2.second) // p2 is start and p1 is end - p2 should come first
            {
                return false;
            }
            else    // both are end points - lower one should come first
                return p1.first.second < p2.first.second;
        }
        else
            return p1.first.first < p2.first.first;
	}
    
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        // use a max heap to keep track of heights
        // whenever the max value changes, add that point to our skyline
        // sort by x points
        
        custom_priority_queue<int> maxheap;
        maxheap.push(0); // initialize max current height as 0
        vector<pair<int, int>> results;
        
        int prev_height = 0;
        vector<pair<pair<int, int>, bool>> bpoints; // pair<pair<point, height>, isStart?>
        
        // we loop through each of the points and separate the points individually
        for(int i = 0 ; i < buildings.size() ; i++)
        {
            pair<int, int> start = pair<int, int>(buildings[i][0], buildings[i][2]);
            bpoints.push_back(pair<pair<int, int>, bool>(start, true));
            
            pair<int, int> end = make_pair(buildings[i][1], buildings[i][2]);
            bpoints.push_back(pair<pair<int, int>, bool>(end, false));
        }
        sort(bpoints.begin(), bpoints.end(), bpointCompare);
        
        for(int i = 0 ; i < bpoints.size() ; i++)
        {
            if (bpoints[i].second == true) // it is the start of a building
            {
                // add the height to the maxheap and update the max height/add to result set if its largest till now
                maxheap.push(bpoints[i].first.second);
            }
            else // it is the end of a building
            {
                // remove that point from the maxheap
                maxheap.remove(bpoints[i].first.second);
                // cout << "Reached end of a building, now max height is " << maxheap.top() << endl;
            }
                
            if (maxheap.top() != prev_height)   // skyline max point has changed
            {
                prev_height = maxheap.top();
                // add the latest point and the top of the new heap now
                results.push_back(pair<int, int>{bpoints[i].first.first, prev_height});
            }
        }
        
        return results;
    }
};
