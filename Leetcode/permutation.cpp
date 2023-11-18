class Solution 
{
    public:
        vector<vector<int>> permute(vector<int>& nums)
        {
            vector<vector<int>> result;
            vector<vector<int>> temp;
            int front;

            if (nums.size() == 1)
            {
                result.push_back(nums);
                return result;
            }

            for (int i = 0; i < nums.size(); i++)
            {
                front = nums.front();
                nums.erase(nums.begin());
                temp = this -> permute(nums);

                for (int j = 0; j < temp.size(); j++)
                {
                    temp[j].push_back(front);
                    result.push_back(temp[j]);
                }
                
                nums.push_back(front);
            }

            return result;
        }
};