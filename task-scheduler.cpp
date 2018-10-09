// https://leetcode.com/problems/task-scheduler
// time complexity - O(N^2), space - O(N)

class Solution {
public:
    void setCooling(int freq[26], char ch, int n, bool idleFlag)
    {
        if (idleFlag)
        {
            for(int i = 0 ; i < 26 ; i++)
                if (freq[i] > 0)
                    freq[i]--;
        }
        else
        {
            freq[ch - 'A'] = n;
            for(int i = 0 ; i < 26 ; i++)
                if (freq[i] > 0 && (i != (int)(ch - 'A')))
                    freq[i]--;
        }
    }
    
    int leastInterval(vector<char>& tasks, int n)
    {
        // input - char array
        // output - min no of intervals
        int result_tasks = 0;
        
        priority_queue<pair<int, char>> pq;
        int freq[26] = {0};
        
        for (char ch : tasks)
            freq[ch - 'A']++;
        
        for(int i = 0 ; i < 26 ; i++)
        {
            if (freq[i] > 0)
                pq.push(pair<int, char>(freq[i], (char)('A' + i)));
            freq[i] = 0;
        }
    
        while (!pq.empty())
        {
            if (freq[pq.top().second - 'A'] != 0) // element is unusable
            {
                vector<pair<int, char>> tempHolder;
                while (!pq.empty() && freq[pq.top().second - 'A'] != 0)
                {
                    // search for next suitable element
                    pair<int, char> ele = pq.top();
                    tempHolder.push_back(ele);
                    pq.pop();
                }
                if (pq.empty()) // empty list
                {
                    result_tasks++; // inserting idle
                    setCooling(freq, 'A', 0, true);
                }
                else
                {
                    // pq.top() element has cooled off and is usable
                    result_tasks++;
                    pair<int, char> ele = pq.top();
                    pq.pop();
                    ele.first -= 1;
                
                    // now set freq[nextch] = n and decrement freq of all other chars
                    setCooling(freq, ele.second, n, false);
                    
                    // push it back unless freq left is 0
                    if (ele.first > 0)
                        pq.push(ele);
                }

                // now reinsert back all the elements temporarily popped
                for(auto ele : tempHolder)
                {
                    pq.push(ele);
                }
            }
            else
            {
                // top element is usable
                result_tasks++;
                pair<int, char> ele = pq.top();
                pq.pop();
                ele.first -= 1;

                // push it back unless freq left is 0
                if (ele.first > 0)
                    pq.push(ele);
                
                // now set freq[top().first] = n and decrement freq of all other chars
                setCooling(freq, ele.second, n, false);
            }
        }
        return result_tasks;
    }
};