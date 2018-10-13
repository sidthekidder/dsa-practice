// https://leetcode.com/problems/count-and-say
// time complexity - O(2^n)

class Solution {
public:
    string countAndSay(int n) 
    {
        unordered_map<int, string> mapping;
        mapping[1] = "1";

        for(int i = 2 ; i <= 30 ; i++)
        {
            string s = mapping[i-1];
            
            stringstream res;
            int cur = 1;
            char curEle = s[0];
            for(int j = 1 ; j < s.length() ; j++)
            {
                if (s[j] != curEle)
                {
                    res << cur << curEle;
                    curEle = s[j];
                    cur = 1;
                }
                else
                    cur++;
            }
            res << cur << curEle;
            mapping[i] = res.str();
        }
        return mapping[n];
    }
};