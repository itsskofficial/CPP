class Solution 
{
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
        {
            vector<vector<int>> result;
            vector<int> combination = {};

            function<void(int, vector<int>&, int)> dfs = [&] (int i, vector<int>& combination, int total) 
            {
                if (total == target)
                {
                    result.push_back(combination);
                    return;
                }

                if (i >= candidates.size() || total > target)
                {
                    return;
                }

                combination.push_back(candidates[i]);
                dfs(i, combination, total + candidates[i]);
                combination.pop_back();

                dfs(i + 1, combination, total);
            };

            dfs(0, combination, 0);
            return result;
        }
};