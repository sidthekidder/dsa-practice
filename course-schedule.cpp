class Solution {
public:
    void moveVertex(int cur, set<int>& set1, set<int>& set2)
    {
        set1.erase(cur);
        set2.insert(cur);
    }
    
    bool dfs(vector<pair<int, int>>& prerequisites, int cur, set<int>& unvisited, set<int>& visiting, set<int>& visited)
    {
        moveVertex(cur, unvisited, visiting);
        
        for(auto it : prerequisites)
        {
            if (it.first == cur && visiting.count(it.second) > 0)
                return true;
            if (it.first == cur && unvisited.count(it.second) > 0)
                if (dfs(prerequisites, it.second, unvisited, visiting, visited))
                    return true;
        }
        
        moveVertex(cur, visiting, visited);
        return false;
    }
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) 
    {
        set<int> unvisited, visiting, visited, allVertices;
        for(auto v : prerequisites)
        {
            unvisited.insert(v.first);
            unvisited.insert(v.second);
            allVertices.insert(v.first);
            allVertices.insert(v.second);
        }
        
        for(auto v : allVertices)
        {
            if (visited.count(v) > 0) continue;
            if (dfs(prerequisites, v, unvisited, visiting, visited))
                return false;
        }
        return true;
    }
};