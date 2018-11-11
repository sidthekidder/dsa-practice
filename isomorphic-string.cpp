// https://leetcode.com/problems/isomorphic-strings
// time complexity - O(N), space complexity - O(N)

class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        unordered_map<char, char> mapping;
        bool mapped[256] = {false};
        for(int i = 0 ; i < s.length() ; i++)
        {
            if (mapping.count(s[i]) > 0) // already mapped
            {
                if (mapping[s[i]] != t[i]) 
                    return false;
            }
            else
            {
                if (mapped[t[i]]) return false;
                
                mapping[s[i]] = t[i];
                mapped[t[i]] = true;
            }
        }
        return true;
    }
};