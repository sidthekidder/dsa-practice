// https://leetcode.com/problems/add-binary
// time complexity - O(max(a, b)), space - O(max(a, b))

class Solution {
public:
    string addBinary(string a, string b)
    {
        // input - 2 strings of binary numbers
        // required - sum in binary
        // start with 2 pointers i,j both at end of strings - beginning of numbers
        //    x  y carry  res, next_carry
        //    1  1  0      0     1
        //    1  0  0      1     0
        //    0  1  0      1     0
        //    0  0  0      0     0
        //    1  1  1      1     1
        //    1  0  1      0     1
        //    0  1  1      0     1
        //    0  0  1      1     0
        
        int i = a.length() - 1, j = b.length() - 1;
        stringstream ss;
        int carry = 0, x, y, z;
        while (true)
        {
            if (i >= 0 && j >= 0)
            {
                x = a[i] - '0';
                y = b[j] - '0';
                z = x ^ y ^ carry;
                if ((x == 1 && y == 1) || (x == 1 && carry == 1) || (y == 1 && carry == 1))
                    carry = 1;
                else
                    carry = 0;
                
                ss << z;
                i--, j--;
            }
            else if (i >= 0)
            {
                x = a[i] - '0';
                z = x ^ carry;
                if (x == 1 && carry == 1)
                    carry = 1;
                else
                    carry = 0;
                
                ss << z;
                i--;
            }
            else if (j >= 0)
            {
                y = b[j] - '0';
                z = y ^ carry;
                if (y == 1 && carry == 1)
                    carry = 1;
                else
                    carry = 0;
                
                ss << z;
                j--;
            }
            else if (carry == 1)
            {
                ss << "1";
                break;
            }
            else
                break;
        }
        string ans = ss.str();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};