// https://leetcode.com/problems/3sum

class Solution 
{
    public:

        vector<vector<int>> threeSum(vector<int>& nums) 
        {
          int index;
          int left;
          int right;
          int threeSum;
          vector<int> temp;
          vector<vector<int>> result;
          vector<int>::iterator iter;
          sort(nums.begin(), nums.end());

          for (iter = nums.begin(); iter < nums.end(); iter++)
          {
              index = iter - nums.begin();
              if (index > 0 && *iter == *(iter - 1))
              {
                continue;
              }

              left = index + 1;
              right = nums.size() - 1;
              while (left < right)
              {
                  threeSum = *iter + nums[left] + nums[right];
                  if (threeSum > 0)
                  {
                      right -= 1;
                  }
                  else if (threeSum < 0)
                  {
                      left += 1;
                  }
                  else 
                  {
                      temp.push_back(*iter);
                      temp.push_back(nums[left]);
                      temp.push_back(nums[right]);
                      result.push_back(temp);
                      temp = {};
                      left += 1;
                      while (nums[left] == nums[left - 1] && left < right)
                      {
                          left += 1;
                      }
                  }
              }
          }

          return result;

        }
};