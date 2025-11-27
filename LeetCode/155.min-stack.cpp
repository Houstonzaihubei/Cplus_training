/*
 * @Author: OBKoro1
 * @Date: 2025-11-27 23:27:58
 * @FilePath: \LeetCode\155.min-stack.cpp
 * @Description: 
 */
/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */


// @lc code=start

//1.辅助栈
/*
class MinStack {
    stack<int> x_stack;
    stack<int> min_stack;
public:
    MinStack() {
        min_stack.push(INT_MAX);
    }
    
    void push(int val) {
        x_stack.push(val);
        min_stack.push(min(min_stack.top(), val));
    }
    
    void pop() {
        x_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return x_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
*/

//2.差值栈（记录最小值，栈中存储与最小值的差值），用途：应对刁钻的面试官（评论区看到的差评面试官）

class MinStack {
public:
    vector<long long> stack;
    long long min;
    MinStack() {
        min = INT_MAX;
    }
    
    void push(int val) {
        if (stack.empty()) {
            stack.push_back(0);
            min = val;
        } else {
            long long diff = val - min;
            stack.push_back(diff);
            min = diff < 0 ? val : min;
        }
    }
    
    void pop() {
        long long diff = stack.back();
        stack.pop_back();
        if (diff < 0) {
            min = min - diff;
        }
    }
    
    int top() {
        long long diff = stack.back();
        return diff < 0 ? min : min + diff;
    }
    
    int getMin() {
        return min;
    }
};



/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

