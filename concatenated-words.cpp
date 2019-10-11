// https://leetcode.com/problems/concatenated-words

class Solution 
{
public:
    bool recurCheck(string word, set<string>& wordset)
    {
        for(int i = 1 ; i < word.length() ; i++)
        {
            string w1 = word.substr(0, i);
            string w2 = word.substr(i);
            if (wordset.count(w1) > 0 && (wordset.count(w2) > 0 || recurCheck(w2, wordset)))
                return true;
        }
        return false;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) 
    {
        // put all words in map
        // split every letter of all words and check if they already exist
        set<string> wordset;
        for(string w : words)
            wordset.insert(w);
        
        vector<string> result;
        for(string w : words)
        {
            for(int i = 1 ; i < w.length() ; i++)
            {
                // split at i
                string w1 = w.substr(0, i);
                string w2 = w.substr(i);

                if (wordset.count(w1) > 0 && (wordset.count(w2) > 0 || recurCheck(w2, wordset)))
                {
                    result.push_back(w);
                    break;
                }
            }
        }
        return result;
    }
};