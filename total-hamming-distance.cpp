// https://leetcode.com/problems/total-hamming-distance
// time complexity - O(N log(no of digits in largest number))

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int sum = 0;
        int numberof0s;
        int numberof1s;
        
        while (true)
        {
            bool nonZeroFlag = false;
            numberof0s = 0;
            numberof1s = 0;
            for(int i = 0 ; i < nums.size() ; i++)
            {
                if (nums[i] % 2 == 0)
                    numberof0s++;
                else
                    numberof1s++;
                if (nums[i] > 0) 
                    nonZeroFlag = true;
                nums[i] = nums[i] >> 1;
            }
            sum += numberof0s * numberof1s;
            if (!nonZeroFlag) break;
        }
        
        return sum;
    }
};