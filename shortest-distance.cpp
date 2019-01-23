// https://leetcode.com/problems/shortest-word-distance
// time complexity - O(N^2), space complexity - O(N)

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) 
    {
        vector<int> a, b;
        for(int i = 0 ; i < words.size() ; i++)
        {
            if (words[i].compare(word1) == 0)
                a.push_back(i);
            else if (words[i].compare(word2) == 0)
                b.push_back(i);
        }
        int mindist = numeric_limits<int>::max();
        
        for(int i : a)
            for(int j : b)
                mindist = min(mindist, abs(i - j));
        return mindist;
    }
};