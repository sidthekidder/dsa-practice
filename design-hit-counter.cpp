// https://leetcode.com/problems/design-hit-counter
// time complexity - O(logN) insert, O(N) getHits

class HitCounter {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        pq.push(timestamp);
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while (!pq.empty() && pq.top() <= (timestamp - 300))
            pq.pop();
        return pq.size();
    }
};