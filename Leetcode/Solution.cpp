// https://leetcode.com/problems/roman-to-integer

class Solution 
{
    public:
        int romanToInt(string s) 
        {
            int n, i, sum = 0;
            n = s.length();

            for (i = 0; i < n; i++)
            {
                switch(s[i])
                {
                    case 'I' :
                    {
                        if (s[i + 1] == 'V') 
                        {
                            sum += 4;
                            i += 1;
                            break;
                        }

                        else if (s[i + 1] == 'X')
                        {
                            sum += 9;
                            i += 1;
                            break;
                        }

                        else
                        {
                            sum += 1;
                            break;
                        }
                    }       
                    case 'V' :
                    {
                        sum += 5;
                        break;
                    }
                        
                    case 'X' :
                    {
                        if (s[i + 1] == 'L') 
                        {
                            sum += 40;
                            i += 1;
                            break;
                        }

                        else if (s[i + 1] == 'C')
                        {
                            sum += 90;
                            i += 1;
                            break;
                        }

                        else
                        {
                            sum += 10;
                            break;
                        }
                    }
                        
                    case 'L' :
                    {
                        sum += 50;
                        break;
                    }
                        
                    case 'C' :
                    {
                        if (s[i + 1] == 'D') 
                        {
                            sum += 400;
                            i += 1;
                            break;
                        }

                        else if (s[i + 1] == 'M')
                        {
                            sum += 900;
                            i += 1;
                            break;
                        }

                        else
                        {
                            sum += 100;
                            break;
                        }
                    }

                    case 'D' :
                    {
                        sum += 500;
                        break;
                    }
                        
                    case 'M' :
                    {
                        sum += 1000;
                        break;
                    }    
                }
            }

            return sum;
        }
};