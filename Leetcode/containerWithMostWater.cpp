// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int area;
        int left = 0;
        int right = height.size() - 1;
        while (left < right)
        {
            area = (right - left) * min(height[left], height[right]);
            result = max(result, area);

            if (height[left] < height[right])
            {
                left += 1;
            }

            else
            {
                right -= 1;
            }
        }

        return result;
    }
};