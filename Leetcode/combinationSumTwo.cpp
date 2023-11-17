class Solution 
{
    public:
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
        {
            sort(candidates.begin(), candidates.end());
            vector<vector<int>> result;
            
            function<void(vector<int> current, int index, int target)> backtrack = [&] (vector<int> current, int index, int target)
            {
                if (target == 0)
                {
                    result.push_back(current);
                }

                if (target <= 0)
                {
                    return;
                }

                int previous = -1;

                for (int i = index; i < candidates.size(); i++)
                {
                    if (candidates[i] == previous) 
                    {
                        continue;
                    }

                    current.push_back(candidates[i]);
                    backtrack(current, i + 1, target - candidates[i]);
                    current.pop_back();

                    previous = candidates[i];
                }
            };

            backtrack({}, 0, target);

            return result;
        }
    };