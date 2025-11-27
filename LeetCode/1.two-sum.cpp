/*
 * @Author: OBKoro1
 * @Date: 2025-11-26 23:34:37
 * @FilePath: \LeetCode\1.two-sum.cpp
 * @Description: 
 */
/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

/*
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] == target - nums[i]) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};
// @lc code=end
*/

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            if (hash.find(target - nums[i] != hash.end())) {
                return {hash[target - nums[i]], i};
            }
            hash[nums[i]] = i;
        }
        return {};
    }
};

// @lc code=end

