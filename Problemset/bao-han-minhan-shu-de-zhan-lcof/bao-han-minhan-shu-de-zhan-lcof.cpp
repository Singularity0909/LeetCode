
// @Title: 包含min函数的栈 (包含min函数的栈 LCOF)
// @Author: Singularity0909
// @Date: 2020-07-20 01:50:08
// @Runtime: 44 ms
// @Memory: 14.8 MB

class MinStack {
public:
    stack<int> a, b;

    MinStack() {}
    
    void push(int x)
    {
        a.push(x);
        if (b.empty() || x <= b.top()) {
            b.push(x);
        }
    }
    
    void pop()
    {
        int x = a.top();
        a.pop();
        if (!b.empty() && b.top() == x) {
            b.pop();
        }
    }
    
    int top()
    {
        return a.top();
    }
    
    int min()
    {
        return b.top();
    }
};
