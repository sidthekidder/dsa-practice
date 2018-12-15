// https://leetcode.com/problems/longest-palindrome
// time complexity - O(N), space complexity - O(1)

class Solution {
public:
    int longestPalindrome(string s) 
    {
        vector<int> freq(256, 0);
        for(char ch : s)
            freq[(int)ch]++;
        
        sort(freq.rbegin(), freq.rend());
        
        int count = 0;
        bool oddFlag = false;
        for(int i = 0 ; i < freq.size() ; i++)
        {
            count += freq[i];
            
            if (freq[i] % 2 != 0)
            {
                if (oddFlag)
                    count -= 1;
                else
                    oddFlag = true;
            }
        }
        return count;
    }
};