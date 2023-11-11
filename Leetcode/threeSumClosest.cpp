// https://leetcode.com/problems/3sum-closest

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        int result;
        int closestSum = INT_MAX;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; ++i) {
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                int currentDiff = abs(currentSum - target);

                if (currentDiff < closestSum) {
                    closestSum = currentDiff;
                    result = currentSum;
                }

                if (currentSum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }

        return result;
    }
};
