// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        if (needle == "") 
        {
            return 0;
        }

        if (needle.length() > haystack.length())
        {
            return -1;
        }
        
        for (int i = 0; i < haystack.length() + 1 - needle.length(); i++)
        {
            for (int j = 0; j < needle.length(); j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    break;
                }

                if (j == needle.length() - 1)
                {
                    return i;
                }
                     
            }
        }

        return -1;
    }
};