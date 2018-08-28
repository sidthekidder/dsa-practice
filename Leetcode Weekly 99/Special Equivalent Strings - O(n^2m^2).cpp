class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) 
    {
        map<string, int> buckets;
        int len = A.size();
        bool visited[len] = {0};

        // for loop over all strings
        for(int i = 0 ; i < len ; i++)
        {
            if (visited[i]) continue;
            buckets[A[i]] = 1;
            // for each string, compare with all other strings
            // which bucket should it go into
            for(int j = i+1 ; j < len ; j++)
            {
                if (visited[j]) continue;
                
                bool result = isSE(A[i], A[j]);
                if (result)
                {
                    visited[j] = true;
                    if (buckets.count(A[i]) == 0) buckets[A[i]] = 1;
                    else buckets[A[i]]++;
                }
            }
        }
        return buckets.size();
    }
    
    bool isSE(string A, string B)
    {
        if (A.size() != B.size()) return false;
        
        int len = A.size();
        for(int i = 0 ; i < len ; i++)
        {
            if (A[i] != B[i])
            {
                bool found = false;
                for(int j = i+2 ; j < len ; j+=2)
                {
                    if (A[i] == B[j])
                    {
                        // swap B[j] and B[i]
                        char temp = B[j];
                        B[j] = B[i];
                        B[i] = temp;
                        found = true;
                        break;
                    }
                }
                if (!found) return false;
            }
        }
        return true;
    }
};