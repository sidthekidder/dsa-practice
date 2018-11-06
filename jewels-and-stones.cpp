// https://leetcode.com/problems/jewels-and-stones
// time complexity - time O(N), space O(N)

class Solution {
public:
    int numJewelsInStones(string J, string S) 
    {
        set<char> exists;
        for(char ch : J)
            exists.insert(ch);
        int count = 0;
        for(char ch : S)
            if (exists.count(ch) > 0)
                count++;
        return count;
    }
};