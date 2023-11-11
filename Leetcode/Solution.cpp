// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution 
{

public:
    int lengthOfLongestSubstring(string s) 
    {
        char arr[128] = {'\0'};
        string temp;
        string ans;
        int isFirst = 0;
        int counter = 0;
        int pos = 0;
        int stringLength = s.length();

        for (int i = 0; i < stringLength; i++)
        {
            int flag = 0;
            char character = s[i];
            for (int j = 0; j < 128; j++)
            {
                if (character == arr[j])
                {
                    flag = 1;
                    if (temp.length() > ans.length())
                    {
                        ans = temp;
                    }

                    pos = temp.find(character);
                    temp = temp.substr(pos + 1, temp.length() - pos - 1);
                    temp += character;
                    for (int l = 0; l < 128; l++)
                    {   
                        arr[l] = '\0';
                    }

                    for (int k = 0; k < temp.length(); k++)
                    {
                        arr[k] = temp[k];
                    }
                    break;
                }
            }

            if (flag == 0 && isFirst != 0)
            {
                for (int k = 1; k < 128; k++)
                {
                    if (arr[k] == '\0' && arr[k-1] == s[i-1])
                    {
                        arr[k] = character;
                        temp += character;
                        break;
                    }

                    else if (arr[k] == '\0' && arr[k-1] != s[i-1])
                    {
                        for (int l = 0; l < 128; l++)
                        {   
                            arr[l] = '\0';
                        }

                        if (temp.length() > ans.length())
                        {
                            ans = temp;
                        }

                        temp = "";
                    }

                    else
                        continue;

                }
            }

            if (flag == 0 && isFirst == 0)
            {
                arr[0] = character;
                temp += character;
                isFirst = 1;
            }

        }

        if (temp.length() > ans.length())
        {
            ans = temp;
        }

        return ans.length();
    }
};