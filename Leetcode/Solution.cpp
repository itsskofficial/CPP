// https://leetcode.com/problems/valid-parentheses

class Solution 
{
public:
    bool isValid(string s) 
    {
        vector<char> open {'(', '{', '['};      
        vector<char> close {')', '}', ']'};      
        stack<char> st;
        char temp;
        int flag = 0;
        bool ans = true;

        for (int i = 0; i < s.length(); i++)
        {
            if (find(open.begin(), open.end(), s[i]) != open.end())
            {
                st.push(s[i]);
            }

            else
            {
                if (st.empty() == true)
                {
                    flag = 1;
                    break;
                }

                temp = st.top();
                st.pop();

                if ((find(open.begin(), open.end(), temp) - open.begin()) != (find(close.begin(), close.end(), s[i]) - close.begin()))
                {
                    flag = 1;
                    break;
                }
            }
        }
   

        if (flag == 1 || st.empty() == false)
        {
            ans = false;
        }   

        return ans;
    }
};