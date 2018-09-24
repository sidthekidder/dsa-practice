// https://leetcode.com/problems/lru-cache
// time complexity - get: O(N), put: O(N)

class LRUCache {
private:
    int size;
    unordered_map<int, int> hashtable;
    deque<pair<int, int>> dq;
public:
    LRUCache(int capacity) {
        // can use a hash table for base key-val pairs
        // to delete LRU, use min-heap with freq count and unique counter ordered?
        // whenever item is inserted, use hash table to point to minheap node
        size = capacity;
    }
    
    void addElementInDeque(int key, int val)
    {
        dq.push_front(pair<int, int>(key, val));
    }
    
    void deleteElementInDeque(int key)
    {
        deque<pair<int, int>> dq2;
        while (!dq.empty())
        {
            if (dq.back().first != key)
                dq2.push_front(dq.back());
            
            dq.pop_back();
        }
        dq = dq2;
    }
    
    int get(int key) 
    {
        if (hashtable.find(key) != hashtable.end())
        {
            // delete the old value
            deleteElementInDeque(key);
            
            // add again to dequeue
            addElementInDeque(key, hashtable[key]);
            
            return hashtable[key];
        }
        else
            return -1;
    }
    
    void put(int key, int value)
    {
        // check if already exists
        if (hashtable.find(key) != hashtable.end())
        {
            // delete the old value
            deleteElementInDeque(key);
            
            // set the new value
            hashtable[key] = value;
            
            // add to dequeue
            addElementInDeque(key, value);
        }
        else
        {
            if (hashtable.size() == size)
            {
                // remove the last element of deque
                pair<int, int> ele = dq.back();
                hashtable.erase(ele.first);
                dq.pop_back();
            }

            // set the new value
            hashtable[key] = value;
            
            // add the value
            addElementInDeque(key, value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */