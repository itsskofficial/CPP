class Solution 
{
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) 
        {
            map<vector<int>, vector<string>> anagrams;
            vector<vector<string>> result;
            

            for (int i = 0; i < strs.size(); i++)
            {
                vector<int> count(26, 0);

                for (int j = 0; j < strs[i].length(); j++)
                {
                    count[static_cast<int>(strs[i][j]) - static_cast<int>('a')] += 1;
                }

                anagrams[count].push_back(strs[i]);
            }

            for (const auto& pair : anagrams) 
            {
                result.push_back(pair.second);
            }

            return result;
        }
};