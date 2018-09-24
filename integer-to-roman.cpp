// https://leetcode.com/problems/integer-to-roman/

class Solution {
public:
    string intToRoman(int num) 
    {
        // start dividing from largest M till I
        // eg 510 -> 500 - D then 10 - X
        // eg 509 -> 500 - D then 9 - special case for 4,9,40,90,400,900
        string ans = "";
        // eg 910
        int modM = num / 1000;
        while (modM)
        {
            ans += "M";
            modM--;
            num -= 1000;
        }

        if (num % 1000 >= 900) 
        {
            ans += "CM";
            num -= 900;
        }

        int modD = num / 500;
        while (modD)
        {
            ans += "D";
            modD--;
            num -= 500;
        }
        if (num % 500 >= 400) 
        {
            ans += "CD";
            num -= 400;
        }
        
        int modC = num / 100;
        while (modC)
        {
            ans += "C";
            modC--;
            num -= 100;
        }
        if (num % 100 >= 90)
        {
            ans += "XC";
            num -= 90;
        }
        
        int modL = num / 50;
        while (modL)
        {
            ans += "L";
            modL--;
            num -= 50;
        }
        if (num % 50 >= 40)
        {
            ans += "XL";
            num -= 40;
        }
        
        int modX = num / 10;
        while (modX)
        {
            ans += "X";
            modX--;
            num -= 10;
        }
        if (num % 10 >= 9)
        {
            ans += "IX";
            num -= 9;
        }
        
        int modV = num / 5;
        while (modV)
        {
            ans += "V";
            modV--;
            num -= 5;
        }
        if (num % 5 == 4)
        {
            ans += "IV";
            num -= 4;
        }
        
        int modI = num / 1;
        while (modI)
        {
            ans += "I";
            modI--;
            num -= 1;
        }
        return ans;
    }
};