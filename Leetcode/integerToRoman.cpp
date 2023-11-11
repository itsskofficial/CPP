// https://leetcode.com/problems/integer-to-roman

class Solution 
{
    public:
        string intToRoman(int num) 
        {
            string s = "", x = "";

            int n = to_string(num).length();
            int r1 = 4, r2 = 9, d1 = 5, d2 = 10, q1 = 0, q2 = 1;
            int temp1, temp2, temp3;

            for (int i = 0; i < n; i++)
            {
                temp3 = num % d2;
                if (temp3 != 0)
                {   
                    if (i < 3)
                    {
                        temp1 = temp3 - q1;
                        if (temp1 > d1)
                        {
                            if (temp1 == r2)
                            {
                                switch(i)
                                {
                                    case 0 :
                                    {
                                        x = "IX";
                                        break;
                                    }
                                        
                                    case 1 :
                                    {
                                        x = "XC";
                                        break;
                                    }
                                        
                                    case 2 :
                                    {
                                        x = "CM";
                                        break;
                                    }

                                }
                            
                            }

                            else
                            {
                                temp2 = temp1 - d1;
                                temp2 = temp2 / q2;
                                
                                for (int j = 0; j < temp2; j++)
                                {
                                    switch(i)
                                    {
                                        case 0 :
                                        {
                                            x += "I";
                                            break;
                                        }
                                            
                                        case 1 :
                                        {
                                            x += "X";
                                            break;
                                        }
                                            
                                        case 2 :
                                        {
                                            x += "C";
                                            break;
                                        }

                                    }
                                }
                                
                                switch(i)
                                {
                                    case 0 :
                                    {
                                        x = "V" + x;
                                        break;
                                    }
                                        
                                    case 1 :
                                    {
                                        x = "L" + x;
                                        break;
                                    }
                                        
                                    case 2 :
                                    {
                                        x = "D" + x;
                                        break;
                                    }
                                }
                            }
                        }

                        else if (temp1 < d1)
                        {
                            temp2 = temp1 / q2;
                            if (temp1 == r1)
                            {
                                switch(i)
                                {
                                    case 0 :
                                    {
                                        x = "IV";
                                        break;
                                    }
                                        
                                    case 1 :
                                    {
                                        x = "XL";
                                        break;
                                    }
                                        
                                    case 2 :
                                    {
                                        x = "CD";
                                        break;
                                    }

                                }
                            }

                            else
                            {
                                for (int j = 0; j < temp2; j++)
                                {
                                    switch(i)
                                    {
                                        case 0 :
                                        {
                                            x += "I";
                                            break;
                                        }
                                            
                                        case 1 :
                                        {
                                            x += "X";
                                            break;
                                        }
                                            
                                        case 2 :
                                        {
                                            x += "C";
                                            break;
                                        }

                                    }
                                }

                            }
                        }

                        else
                        {
                            switch(i)
                            {
                                case 0 :
                                {
                                    x = "V";
                                    break;
                                }
                                    
                                case 1 :
                                {
                                    x = "L";
                                    break;
                                }
                                    
                                case 2 :
                                {
                                    x = "D";
                                    break;
                                }

                            }
                        }
                    }
                    else 
                    {
                        temp1 = temp3 - q1;
                        temp2 = temp1 / q2;
                        for (int j = 0; j < temp2; j++)
                        {
                            x += "M";
                        }
                    }
                }
                s = x + s;
                q1 = temp3;
                x = "";
                d1 *= 10;
                d2 *= 10;
                r1 *= 10;
                r2 *= 10;
                q2 *= 10;
            }
        return s;
        }
};