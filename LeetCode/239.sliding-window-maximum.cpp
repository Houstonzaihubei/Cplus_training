/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
/*
方法1：单调双端队列
双端队列：提供一个类双端队列
单调队列：保证队列的队头为所需最大值
*/
/*
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> q;
        for (int i = 0; i < k; i++) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        ans.push_back(nums[q.front()]);

        for (int i = k; i < n; i++) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            while (q.back() - q.front() >= k) {
                q.pop_front();
            }
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};
*/

/*
方法2：优先队列
使用大根堆解题即可。记住priority_queue相关函数调用的用法
*/
/*
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> q;
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            q.emplace(nums[i], i);//第一个位置为对应的温度index，第二个位置为index，加入优先队列
        }
        ans.push_back(q.top().first);
        for (int i = k; i < n; i++) {
            q.emplace(nums[i], i);
            while (q.top().second <= i - k) {//i - k是滑动窗口的左边界
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
};
*/
/*
方法3：分块+预处理
这个方法真的太巧妙了，我感到叹服
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        vector<int> ans(n - k + 1);
        for (int i = 0; i < n; i++) {
            if (i % k == 0) {
                prefix[i] = nums[i];
            } else {
                prefix[i] = max(prefix[i - 1], nums[i]);
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if ((i + 1) % k == 0 || i == n - 1) {
                suffix[i] = nums[i];
            } else {
                suffix[i] = max(suffix[i + 1], nums[i]);
            }
        }

        for (int i = 0; i < n - k + 1; i++) {
            ans[i] = max(prefix[i + k - 1], suffix[i]);
        }
        return ans;
    }
};
// @lc code=end

