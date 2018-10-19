// https://leetcode.com/problems/word-ladder
// time complexity - O(N), space complexity - O(N)

class Solution {
public:
    
    bool is1Away(string s1, string s2)
    {
        int count = 0;
        for(int i = 0 ; i < s1.length() ; i++)
        {
            if (s1[i] != s2[i])
            {
                count++;
                if (count > 1)
                    return false;
            }
        }
        return (count == 1);
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        // input - begin string, target string, list of intermediate strings
        // output - min number of transformations, 0 if not possible
        // hit - cog, hit->hot->dot->dog->cog
        unordered_set<string> visitedWords;
        unordered_set<string> allWords(wordList.begin(), wordList.end());
        
        // do a BFS - change begin word to all possible words 1 letter away
        // if that exists in dict and not visited yet, push into BFS queue
        // then pick up next word from queueu and again transform
        // keep a visited array so that we don't repeat 
        queue<pair<string, int>> bfs;
        bfs.push(pair<string, int>(beginWord, 1));
        visitedWords.insert(beginWord);
        
        while (!bfs.empty())
        {
            pair<string, int> ele = bfs.front();
            bfs.pop();

            if (endWord.compare(ele.first) == 0) // if we find the target
                return ele.second;
            
            for(int i = 0 ; i < ele.first.length() ; i++)
            {
                string word = ele.first;
                for(char a = 'a' ; a <= 'z' ; a++) // generate all neighbor words
                {
                    word[i] = a;
                    if (visitedWords.count(word) == 0 && allWords.count(word) > 0)
                    {
                        visitedWords.insert(word);
                        bfs.push(pair<string, int>(word, ele.second+1));
                    }
                }
            }
        }
        return 0;
    }
};