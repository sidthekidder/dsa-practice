// https://leetcode.com/problems/complex-number-multiplication/
// time complexity - O(1), space complexity - O(1)

class Solution {
public:
    typedef struct ci
    {
        int real;
        int complex;
    } ci;
    
    ci get_complex_number(string a)
    {
        int idx = a.find("+");
        int real = stoi(a.substr(0, idx));
        a = a.substr(idx + 1);
        idx = a.find("i");
        int complex = stoi(a.substr(0, idx));
        
        ci c; c.real = real; c.complex = complex;
        return c;
    }

    string complexNumberMultiply(string a, string b) 
    {
        ci c1 = get_complex_number(a);
        ci c2 = get_complex_number(b);
        
        ci c;
        c.real = (c1.real * c2.real) - (c1.complex * c2.complex);
        c.complex = (c1.real * c2.complex) + (c1.complex * c2.real);
        stringstream res;
        res << c.real << "+" << c.complex << "i";
        return res.str();
    }
};