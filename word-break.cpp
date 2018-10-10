// https://leetcode.com/problems/word-break/
// time compexity - O(n^2), space complexity - O(n)

class Solution {
public:
    bool checkWord(unordered_map<string, bool> &dict, unordered_map<int, bool>& memoize, string str, int idx)
    {
        if (idx >= str.length())
            return true;
        
        if (memoize.find(idx) != memoize.end()) 
            return memoize[idx];
      
        for(int i = str.length() - idx ; i >= 1  ; i--)
        {
            // break the string from idx to i
            string possibleWord = str.substr(idx, i);
            if (dict[possibleWord])
            {
                if (checkWord(dict, memoize, str, idx + i))
                {
                    memoize[idx+i] = true;
                    return memoize[idx+i];
                }
            }
        }
        memoize[idx] = false;
        return memoize[idx];
    }
    
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        // input - string and list of words
        // output - boolean
        // we can put each word in the dict into a hashmap for O(1) searching
        // try recursive solution starting from index 0 - break the string at index i=1-n if word i exists
        // then check the remaining string recursively
        // 
        unordered_map<string, bool> dict;
        for(string s : wordDict)
            dict[s] = true;
        
        unordered_map<int, bool> memoize;
        
        return checkWord(dict, memoize, s, 0);
    }
};