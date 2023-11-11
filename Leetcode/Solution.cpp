// https://leetcode.com/problems/reverse-integer

class Solution 
{
    public:
        int reverse(int x) 
        {
            int MIN = INT_MIN;
            int MAX = INT_MAX;
            int result = 0;
            int digit;

            while (x) 
            {
                digit = x % 10;
                x = x / 10;

                if (result > MAX / 10 || (result == MAX / 10 && digit >= MAX % 10))
                {
                    return 0;
                }

                if (result < MIN / 10 || (result == MIN / 10 && digit <= MIN % 10))
                {
                    return 0;
                }

                result = (result * 10) + digit;
            }

            return result;
        }
};