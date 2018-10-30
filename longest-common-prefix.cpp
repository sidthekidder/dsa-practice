// time complexity - O(min(length) * no of strings)
// space complexity - O(1)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string result;
        if (strs.size() == 0) 
            return result;

        int idx = 0;
        while (true)
        {
            if (idx >= strs[0].length()) 
                return result;
            
            char ch = strs[0][idx];
            for(int i = 1 ; i < strs.size() ; i++)
                if (idx >= strs[i].length() || ch != strs[i][idx])
                    return result;

            result += ch;
            idx++;
        }
        return result;
    }
};