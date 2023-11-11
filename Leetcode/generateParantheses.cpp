// https://leetcode.com/problems/generate-parentheses

class Solution 
{
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> res;
        string temp = "";

        function<void(int, int)> backtrack = [&](int open, int closed)
        {
            if (open == n && closed == n) 
            {
                res.push_back(temp);
                return;
            }

            if (open < n) 
            {
                temp.push_back('(');
                backtrack(open + 1, closed);
                temp.pop_back();
            }

            if (closed < open) 
            {
                temp.push_back(')');
                backtrack(open, closed + 1);
                temp.pop_back();
            }
        };

        backtrack(0, 0);

        return res;
    }
};
