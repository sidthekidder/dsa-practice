// https://leetcode.com/problems/shifting-letters/
// time complexity - O(N), space complexity - O(N)

class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) 
    {
        // input string and int array
        // output - shifted string
        // build a reverse cumulative sum array so that we have to apply shift operation only once on a letter
        vector<double> cumSum(shifts.size());
        double sum = 0;
        for(double i = shifts.size() - 1 ; i >= 0 ; i--)
        {
            sum += shifts[i];
            cumSum[i] = sum;
        }
        
        // now loop through each number of cumsum and transform each corresponding char of S
        string result = S;
        for(int i = 0 ; i < S.length() ; i++)
        {
            double newChar = S[i] + cumSum[i];
            if (newChar > 122)
                newChar = newChar - (ceil((double)(newChar-122)/26.0))*26;
            result[i] = (char)newChar;
        }
        return result;
    }
};