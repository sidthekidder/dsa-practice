// https://leetcode.com/problems/unique-email-addresses
// time complexity - O(N), space - O(N)

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) 
    {
        unordered_set<string> freq;
        for(string str : emails)
        {
            int rate_idx = str.find("@");
            string second_part = str.substr(rate_idx + 1);
            string first_part = str.substr(0, rate_idx);
            stringstream ss;
            for(int i = 0 ; i < first_part.length() ; i++)
            {
                if (first_part[i] == '.')
                    continue;
                if (first_part[i] == '+')
                    break;
                ss << first_part[i];
            }
            ss << second_part;
            freq.insert(ss.str());
        }
        return freq.size();
    }
};
