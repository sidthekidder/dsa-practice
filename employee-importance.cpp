// https://leetcode.com/problems/employee-importance/
// time complexity - O(N), space complexity - O(N)

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int sum = 0;
        map<int, Employee*> mapping;
        for(Employee* e : employees)
            mapping[e->id] = e;
        
        queue<int> ids;
        ids.push(id);
        while (!ids.empty())
        {
            int getid = ids.front();
            ids.pop();
            sum = sum + mapping[getid]->importance;
            for(int x : mapping[getid]->subordinates)
                ids.push(x);
        }
        return sum;
    }
};