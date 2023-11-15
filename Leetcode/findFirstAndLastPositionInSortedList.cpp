class Solution 
{
    public:
        vector<int> searchRange(vector<int>& nums, int target) 
        {

            vector<int> result;
            int temp;
            
            function<int(vector<int>& , int, bool)> binSearch = [&] (vector<int>& nums, int target, bool leftBias)
            {
                int left = 0;
                int right = nums.size() - 1;
                int middle;
                int index = -1;
                

                while (left <= right)
                {
                    middle = (left + right) / 2;
                    
                    if (target > nums[middle])
                    {
                        left = middle + 1;
                    }

                    else if (target < nums[middle])
                    {
                        right = middle - 1;
                    }

                    else
                    {
                        index = middle;

                        if (leftBias == true)
                        {
                            right = middle - 1;
                        }

                        else 
                        {
                            left = middle + 1;
                        }
                    }
                }

                return index;
            };

            temp = binSearch(nums, target, true);
            result.push_back(temp);
            temp = binSearch(nums, target, false);
            result.push_back(temp);

            return result;
        }
};