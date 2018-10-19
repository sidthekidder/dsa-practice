// https://leetcode.com/problems/lru-cache/
// time complexity - O(1), space complexity - O(N)

class LRUCache {
private:
    int size;
    unordered_map<int, list<pair<int, int>>::iterator> hashtable;
    list<pair<int, int>> lru_list;
public:
    LRUCache(int capacity) {
        // use a list that stores int,int for k-v
        // use a hash table for storing key as item and value as iterator pointer to list
        // to delete LRU, get the iterator from the hash table then erase the list element
        // to update freq of a key, erase the list element then push it again to the list
        // to remove the LRU, pop the top of the list element and delete that key
        size = capacity;
    }
    
    int get(int key) 
    {
        if (hashtable.find(key) != hashtable.end())
        {
            list<pair<int, int>>::iterator res = hashtable[key];
            pair<int, int> result = *res;
            // push this to the front
            lru_list.erase(res);
            lru_list.push_front(pair<int, int>(result.first, result.second));
            hashtable[key] = lru_list.begin();
            
            return result.second;
        }
        else
            return -1;
    }
    
    void put(int key, int value)
    {
        // check if already exists
        if (hashtable.find(key) != hashtable.end())
        {
            list<pair<int, int>>::iterator res = hashtable[key];
            lru_list.erase(res);
            lru_list.push_front(pair<int, int>(key, value));
            hashtable[key] = lru_list.begin();
        }
        else
        {
            pair<int, int> ele = pair<int, int>(key, value);
            lru_list.push_front(ele);
            hashtable[key] = lru_list.begin();
            
            if (lru_list.size() > size)
            {
                // pop the last element
                pair<int, int> popped = lru_list.back();
                lru_list.pop_back();
                hashtable.erase(popped.first);
            }
        }
    }
};
