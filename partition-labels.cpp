// https://leetcode.com/problems/partition-labels
// time complexity - O(N), space complexity - O(1)

class Solution {
public:
    int get_last_idx(string S, int idx)
    {
        int last_idx;
        for(last_idx = S.length() - 1 ; last_idx >= idx ; last_idx--)
            if (S[last_idx] == S[idx]) 
                break;
        return last_idx;
    }
    
    void getPartitions(string &S, int idx, vector<int>& result)
    {
        if (idx < S.length())
        {
            // find last occurrence of current idx
            int last_idx = get_last_idx(S, idx);
            int max_len = last_idx - idx + 1;
            
            // for all chars between idx and last_idx, repeat
            for(int i = idx + 1 ; i < last_idx ; i++)
            {
                int cur_last_idx = get_last_idx(S, i);
                if (cur_last_idx > last_idx) 
                {
                    last_idx = cur_last_idx;
                    max_len = max(max_len, cur_last_idx - idx + 1);
                }
            }
            result.push_back(max_len);
            getPartitions(S, last_idx + 1, result);
        }
    }
    
    vector<int> partitionLabels(string S) 
    {
        // start from first letter and go till last occurrence of that char
        // now for each inner char see the max length required
        // this is first part, repeat for remaining string etc
        vector<int> result;
        getPartitions(S, 0, result);
        return result;
    }
};