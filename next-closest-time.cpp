// https://leetcode.com/problems/next-closest-time/
// time complexity - O(3600)

class Solution {
public:
    bool sameDigits(int hours, int mins, int hours_t, int mins_t)
    {
        stringstream s1;
        if (hours >= 10) s1 << hours;
        else s1 << "0" << hours;
        if (mins >= 10) s1 << mins;
        else s1 << "0" << mins;
        string str1 = s1.str();
        
        stringstream s2;
        if (hours_t >= 10) s2 << hours_t;
        else s2 << "0" << hours_t;
        if (mins_t >= 10) s2 << mins_t;
        else s2 << "0" << mins_t;
        string str2 = s2.str();
        
        int arr[10] = {false};
        for(char ch : str2)
            arr[ch - '0'] = true;
        
        for(char ch : str1)
            if (arr[ch - '0'] == false)
                return false;

        return true;
    }
    
    string nextClosestTime(string time) 
    {
        // input - HH:MM
        // output - next closest time
        // we can loop through all 3600 minutes of a day to find first/last highest as well (with same digits)
        
        int hours_t = stoi(time.substr(0, 2));
        int mins_t = stoi(time.substr(3, 2));
        bool min_found = false, max_found = false;
        int min_hours = -1, min_mins = -1, max_hours = -1, max_mins = -1;
        
        for(int hours = 0 ; hours <= 23 ; hours++)
        {
            for(int mins = 0 ; mins < 60 ; mins++)
            {
                if (!min_found && sameDigits(hours, mins, hours_t, mins_t))
                {
                    min_found = true;
                    min_hours = hours;
                    min_mins = mins;
                }
                if (((hours == hours_t && mins > mins_t) || (hours > hours_t)) && sameDigits(hours, mins, hours_t, mins_t))
                {
                    max_hours = hours;
                    max_mins = mins;
                    max_found = true;
                    break;
                }
            }
            if (max_found) break;
        }
        stringstream ss;
        if (!max_found) // had to go into next day
        {
            if (min_hours >= 10) ss << min_hours;
            else ss << "0" << min_hours;
            ss << ":";
            if (min_mins >= 10) ss << min_mins;
            else ss << "0" << min_mins;
        }
        else
        {
            if (max_hours >= 10) ss << max_hours;
            else ss << "0" << max_hours;
            ss << ":";
            if (max_mins >= 10) ss << max_mins;
            else ss << "0" << max_mins;
        }
        return ss.str();
    }
};