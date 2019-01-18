// https://leetcode.com/problems/positions-of-large-groups
// time complexity - O(N), space complexity - O(1)

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) 
    {
        vector<vector<int>> ans;
        char cur; 
        char prev = '-';
        int count = 0, start_idx = -1;
        for(int i = 0 ; i < S.size() ; i++)
        {
            cur = S[i];
            if (cur == prev)
            {
                if (count == 0)
                    start_idx = i - 1;
                
                count++;
                if (i == S.size() - 1 && count >= 2)
                    ans.push_back({start_idx, i});
            }
            else
            {
                if (count >= 2)
                    ans.push_back({start_idx, i-1});
                count = 0;
            }
            prev = cur;
        }
        return ans;
    }
};
