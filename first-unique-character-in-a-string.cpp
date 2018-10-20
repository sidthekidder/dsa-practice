// https://leetcode.com/problems/first-unique-character-in-a-string
// time complexity - O(N), space complexity - O(1)

class Solution {
public:
    int firstUniqChar(string s) 
    {
        vector<int> arr(26, 0);
        for(int i = 0 ; i < s.length() ; i++)
            arr[s[i] - 'a']++;

        for(int i = 0 ; i < s.length() ; i++)
            if (arr[s[i] - 'a'] == 1)
                return i;
        return -1;
    }
};