// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int left = 1;
        int right;

        for (right = 1; right < nums.size(); right++)
        {
            if (nums[right] != nums[right - 1])
            {
                nums[left] = nums[right];
                left += 1;
            }
        }

        return left;
    }
};