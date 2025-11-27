/*
 * @Author: OBKoro1
 * @Date: 2025-11-27 16:53:25
 * @FilePath: \LeetCode\42.trapping-rain-water.cpp
 * @Description: 
 */
/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start

/*
方法1：动态规划
通过从左向右遍历以及从右向左遍历最终取最小值与砖块做差得到水的面积
*/
/*
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
*/

/*
方法2：单调栈
单调栈的思想：寻找低谷处两侧的高海拔，最终算出水的面积
 */
/*
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> stk;
        int n = height.size();
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int top = stk.top();
                stk.pop();
                if (stk.empty()) {
                    break;
                }
                int left = stk.top();
                int currWidth = i - left - 1;
                int currHeight = min(height[left], height[i]) - height[top];
                ans += currWidth * currHeight;
            }
            stk.push(i);
        }
        return ans;
    }
};
*/

/*
方法3：双指针
思路大体同方法1雷同，即寻找出应有的高度，进行相减得到答案
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int left = 0;
        int right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        while (left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if (height[left] < height[right]) {
                ans += leftMax - height[left];
                left++;
            } else {
                ans += rightMax - height[right];
                right--;
            }
        }
        return ans;
    }
};
// @lc code=end

