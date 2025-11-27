/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        vector<int> array1(height.size());
        vector<int> array2(height.size());
        array1[0] = height[0];
        for (int i = 1; i < height.size(); i++) {
            array1[i] = max(array1[i - 1], height[i]);
        }
        array2[height.size() - 1] = height[height.size() - 1];
        for (int i = height.size() - 2; i >= 0; i--) {
            array2[i] = max(array2[i + 1], height[i]);
        }

        int sum = 0;
        for (int i = 0; i < height.size(); i++) {
            sum += min(array1[i], array2[i]) - height[i];
        }
        return sum;
    }
};
// @lc code=end

