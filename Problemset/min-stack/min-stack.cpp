
// @Title: 最小栈 (Min Stack)
// @Author: Singularity0909
// @Date: 2020-07-20 02:10:04
// @Runtime: 44 ms
// @Memory: 14.1 MB

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
    
    int getMin()
    {
        return b.top();
    }
};
