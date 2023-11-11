// https://leetcode.com/problems/zigzag-conversion

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) 
        {
            return s;
        }

        string result = "";
        int increment;

        for (int i = 0; i < numRows; i++)
        {
            increment = 2 * (numRows - 1);
            for (int j = i; j < s.length(); j = j + increment)
            {
                result = result + s[j];
                if (i > 0 && i < numRows - 1 && j + increment - 2 * i < s.length())
                {
                    result = result + s[j + increment - 2 * i];
                }
            }
        }

        return result;
    }
};