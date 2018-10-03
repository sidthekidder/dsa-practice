// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// time complexity - O(3^n), space complexity - O(3^n) call stack

class Solution {
public:
    void mappingRecursive(string& digits, int idx, string curStr, vector<string>& result)
    {
        if (idx == digits.size())
        {
            if (curStr != "")
                result.push_back(curStr);
        }
        else if (idx < digits.size())
        {
            if (digits[idx] == '1')
            {
                mappingRecursive(digits, idx+1, curStr, result);
            }
            else if (digits[idx] == '2')
            {
                mappingRecursive(digits, idx+1, curStr+"a", result);
                mappingRecursive(digits, idx+1, curStr+"b", result);
                mappingRecursive(digits, idx+1, curStr+"c", result);
            }
            else if (digits[idx] == '3')
            {
                mappingRecursive(digits, idx+1, curStr+"d", result);
                mappingRecursive(digits, idx+1, curStr+"e", result);
                mappingRecursive(digits, idx+1, curStr+"f", result);
            }
            else if (digits[idx] == '4')
            {
                mappingRecursive(digits, idx+1, curStr+"g", result);
                mappingRecursive(digits, idx+1, curStr+"h", result);
                mappingRecursive(digits, idx+1, curStr+"i", result);
            }
            else if (digits[idx] == '5')
            {
                mappingRecursive(digits, idx+1, curStr+"j", result);
                mappingRecursive(digits, idx+1, curStr+"k", result);
                mappingRecursive(digits, idx+1, curStr+"l", result);
            }
            else if (digits[idx] == '6')
            {
                mappingRecursive(digits, idx+1, curStr+"m", result);
                mappingRecursive(digits, idx+1, curStr+"n", result);
                mappingRecursive(digits, idx+1, curStr+"o", result);
            }
            else if (digits[idx] == '7')
            {
                mappingRecursive(digits, idx+1, curStr+"p", result);
                mappingRecursive(digits, idx+1, curStr+"q", result);
                mappingRecursive(digits, idx+1, curStr+"r", result);
                mappingRecursive(digits, idx+1, curStr+"s", result);
            }
            else if (digits[idx] == '8')
            {
                mappingRecursive(digits, idx+1, curStr+"t", result);
                mappingRecursive(digits, idx+1, curStr+"u", result);
                mappingRecursive(digits, idx+1, curStr+"v", result);
            }
            else if (digits[idx] == '9')
            {
                mappingRecursive(digits, idx+1, curStr+"w", result);
                mappingRecursive(digits, idx+1, curStr+"x", result);
                mappingRecursive(digits, idx+1, curStr+"y", result);
                mappingRecursive(digits, idx+1, curStr+"z", result);
            }
        }
    }
    
    vector<string> letterCombinations(string digits) 
    {
        // input is string of digits of length n
        // output - array of strings each of length n - all possible combinations
        vector<string> result;
        mappingRecursive(digits, 0, "", result);

        return result;
    }
};