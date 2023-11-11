// https://leetcode.com/problems/string-to-integer-atoi

class Solution {
public:
    int myAtoi(string s) 
    {
        s = regex_replace(s, std::regex("^ +| +$|( ) +"), "$1");


        if (s.empty())
        {
            return 0;
        }
            
        const int sign = s[0] == '-' ? -1 : 1;

        if (s[0] == '+' || s[0] == '-')
        {
            s = s.substr(1);
        }
        

        long num = 0;

        for (const char c : s) 
        {
            if (!isdigit(c))
            {
                break;
            }
                
            num = num * 10 + (c - '0');

            if (sign * num < INT_MIN)
            {
                return INT_MIN;
            }
                
            if (sign * num > INT_MAX)
            {
                return INT_MAX;
            }
        }

        return sign * num;
    }
};