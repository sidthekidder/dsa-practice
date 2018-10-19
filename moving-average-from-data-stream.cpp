// https://leetcode.com/problems/moving-average-from-data-stream
// time complexity - O(1), space complexity - O(size)

class MovingAverage {
public:
    queue<int> q;
    int capacity;
    int sum;
    
    MovingAverage(int size) {
        capacity = size;
        sum = 0;
    }
    
    double next(int val) {
        if (q.size() == capacity)
        {
            sum -= q.front();
            q.pop();
        }
        q.push(val);
        sum += val;
        
        return (double)sum / (double)q.size();
    }
};
