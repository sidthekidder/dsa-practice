//https://leetcode.com/problems/group-anagrams/description/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        map<string, vector<string>> counts;
        
        for(auto s : strs)
        {
            string ss = s;
            sort(s.begin(), s.end());
            counts[s].push_back(ss);
        }

        vector<vector<string>> result;
        for(auto i : counts)
        {
            result.push_back(i.second);
        }
        
        return result;
    }
};