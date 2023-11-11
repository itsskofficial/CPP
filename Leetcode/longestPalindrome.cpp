// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    void findLongestPalindrome(int &left, int &right, string &result, int &resultLength, string &s)
    {
        while (left >= 0 && right < s.length() && s[left] == s[right])
            {
                if ((right - left + 1) > resultLength)
                {
                    result = s.substr(left, right + 1 - left);
                    resultLength = right - left + 1;
                }

                left = left - 1;
                right = right + 1;
            }
    }

    string longestPalindrome(string s) {
        string result = "";
        int resultLength = 0;

        for (int i = 0; i < s.length(); i++)
        {
            int left = i;
            int right = i;
            
            findLongestPalindrome(left, right, result, resultLength, s);

            left = i;
            right = i + 1;

            findLongestPalindrome(left, right, result, resultLength, s);
        }

        return result;
    }
};