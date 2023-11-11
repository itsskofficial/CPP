// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution 
{
    public:
        vector<string> letterCombinations(string digits) 
        {
            vector<string> res;
            map<string, string> digitToChar = {
                {"2", "abc"},
                {"3", "def"},
                {"4", "ghi"},
                {"5", "jkl"},
                {"6", "mno"},
                {"7", "qprs"},
                {"8", "tuv"},
                {"9", "wxyz"}
            };

            function<void(int, string)>  backtrack = [&](int i, string currentString)
            {
                if (currentString.length() == digits.length())
                {
                    res.push_back(currentString);
                    return;
                }

                string digit(1, digits[i]);

                for (int j = 0; j < digitToChar[digit].length(); j++)
                {
                    string c(1, digitToChar[digit][j]);
                    backtrack(i + 1, currentString + c);
                }
            };

            if (!digits.empty())
            {
                backtrack(0, "");
            }

            return res;
        }
};