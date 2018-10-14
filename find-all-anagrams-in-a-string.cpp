// https://leetcode.com/problems/find-all-anagrams-in-a-string
// time complexity - O(n), space complexity - O(1) (26-size constant arr)

class Solution {
public:
    void getFrequency(string str, int arr[26])
    {
        for(char ch : str)
            arr[ch - 'a']++;
    }
    
    bool compareFreq(int arr1[26], int arr2[26])
    {
        for(int i = 0 ; i < 26 ; i++)
            if (arr1[i] != arr2[i])
                return false;
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int> results;
        
        int parr[26] = {0};
        getFrequency(p, parr);
        
        int i = 0, j = p.length();
        int sarr[26] = {0};
        string start = s.substr(i, j);
        getFrequency(start, sarr);
        
        if (compareFreq(parr, sarr))
            results.push_back(0);
        
        for(i = 0 ; j < s.length() ; i++, j++)
        {
            sarr[s[i] - 'a']--;
            sarr[s[j] - 'a']++;
            if (compareFreq(parr, sarr))
                results.push_back(i+1);
        }
        
        return results;
    }
};