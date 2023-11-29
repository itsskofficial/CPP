class Solution 
{
    public:
        double myPow(double x, int n) 
        {
            double result;

            function<double(double, int)> helper = [&] (double x, int n)
            {
                if (x == 0)
                {
                    return static_cast<double>(0);
                }

                if (n == 0)
                {
                    return static_cast<double>(1);
                }

                result = helper(x, n / 2);
                result *= result;

                if (n % 2 != 0)
                {
                    result *= x;
                    return result;
                }
        
                return result;
                
            };

            result = helper(x, abs(n));

            if (n >= 0)
            {
                return result;
            }

            else 
            {
                return 1 / result;
            }
        }
};