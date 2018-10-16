// https://leetcode.com/problems/maximum-swap/
// time complexity - O(N^2)

class Solution {
public:
    int maximumSwap(int num) 
    {
        // take the string of the number
        // start from MSB - 0th index and keep track of highest value till now (strictly greater)
        // at end of loop if highestTillNow > msb, swap 0 and highestTillNow index
        stringstream ss;
        ss << num;
        string numb = ss.str();
        int highest_idx = 0;
        int swap_idx = 0;
        for(int a = 0 ; a < numb.length() ; a++)
        {
            char highest = numb[a];
            highest_idx = a;
            swap_idx = a;
            for(int i = a + 1 ; i < numb.length() ; i++)
            {
                if (numb[i] > highest || (numb[i] == highest && highest_idx != swap_idx))
                {
                    highest = numb[i];
                    highest_idx = i;
                }
            }
            if (highest_idx != a)
                break;
        }
        swap(numb[highest_idx], numb[swap_idx]);
        return stoi(numb);
    }
};