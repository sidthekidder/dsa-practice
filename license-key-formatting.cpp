// https://leetcode.com/problems/license-key-formatting/
// time complexity - O(N), space complexity - O(N)

class Solution {
public:
    string licenseKeyFormatting(string S, int K) 
    {
        stringstream ss;
        for(char ch : S)
            if (ch != '-')
                ss << ch;
        
        string SS = ss.str();
        int count = 0;
        stringstream ss1;
        for(int i = SS.size() - 1 ; i >= 0 ; i--)
        {
            count++;
            if (SS[i] >= 97 && SS[i] <= 122) 
                SS[i] -= 32;
            if (count == K)
            {
                ss1 << SS[i];
                if (i != 0) ss1 << "-";
                count = 0;
            }
            else
                ss1 << SS[i];
        }
        string res = ss1.str();
        reverse(res.begin(), res.end());
        return res;
    }
};