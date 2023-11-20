class Solution 
{
    public:
        vector<vector<int>> permuteUnique(vector<int>& nums) 
        {
            vector<vector<int>> result;
            vector<int> permutation;
            map<int, int> count;

            for (int i = 0; i < nums.size(); i++)
            {
                count[nums[i]] = 0;
            }

            for (int j = 0; j < nums.size(); j++)
            {
                count[nums[j]] += 1;
            }


            function<void()> dfs = [&] ()
            {
                if (permutation.size() == nums.size())
                {
                    result.push_back(permutation);
                    return;
                }

                 for (auto& kv : count)
                {
                    if (kv.second > 0)
                    {
                        permutation.push_back(kv.first);
                        kv.second -= 1;
                        dfs();
                        kv.second += 1;
                        permutation.pop_back();
                    }
                }
            };

            dfs();
            return result;

        }
};