// https://leetcode.com/problems/partition-labels
// time complexity - O(N), space complexity - O(1)

class Solution 
{
public:
    vector<int> partitionLabels(string S) 
    {
        // i = 0, find last occurrence of S[i] = j
        // loop i-j, for each char, find last occurrence, set j = lastOcc
        // when reached, store j-i in result
        
        // pre-calculate last occurrence array
        vector<int> res;
        int lastIdx[26] = {-1};
        for(int i = 0 ; i < S.size() ; i++)
            lastIdx[S[i] - 'a'] = i;
        
        int i = 0;
        while (i < S.size())
        {
            int lastOcc = lastIdx[S[i] - 'a'];
            if (lastOcc == -1)
            {
                res.push_back(1);
                i++;
                continue;
            }
            
            int origI = i;
            while (i < lastOcc)
            {
                i++;
                if (i == S.size())
                    break;

                int newOcc = lastIdx[S[i] - 'a'];
                if (newOcc > lastOcc)
                    lastOcc = newOcc;
            }
            res.push_back(lastOcc - origI + 1);
            i++;
        }
        
        return res;
    }
};