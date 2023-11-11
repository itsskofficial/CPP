// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int x) {
        string num1;
        string num2;
        int i;
        int j;
        bool palindrome;
        num1 = to_string(x);
        
        for (i = num1.length() - 1; i >= 0 ; i--)
        {
            num2 += num1[i];
            j++;
        }

        if (num1 == num2)
            palindrome = true;
        else 
            palindrome = false;

        return  palindrome;
    }
};