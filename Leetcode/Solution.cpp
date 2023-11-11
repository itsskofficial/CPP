// https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string shortestString(vector<string> strs) 
    {
        string shortest;
        int temp = 0;
        int i = 0;
        for (string s : strs) 
        {
            if (i == 0) 
            {
                temp = s.length();
                shortest = s;
                i++;
            }
            else if (s.length() < temp) 
            {
                temp = s.length();
                shortest = s;
            }
        }

        return shortest;
    }
    
    string longestCommonPrefix(vector<string>& strs) 
    {
        int counter = 0;
        int i = 0;
        int flag = 0;
        int n = 0;
        char c = '\0';
        string answer = "";
        string temp = "";

        n = shortestString(strs).length();

        while(counter < n)
        {
            for (auto& iter : strs)
            {
                temp += iter[counter];
            }

            c = temp[0];

            for (i = 1; i < temp.length(); i++)
            {
                if (c != temp[i])
                {
                    flag = 1;
                    break;
                }
            }

            if (flag == 1 && counter == 0)
            {
                return answer;
            }

            if (flag == 1)
            {
                return answer;
            }

            else
            {
                answer += c;
                temp = "";
                c = '\0';
                counter++;
            }
        }

        return answer;
    }
};