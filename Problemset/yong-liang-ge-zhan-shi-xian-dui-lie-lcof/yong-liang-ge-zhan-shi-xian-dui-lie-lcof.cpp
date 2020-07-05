
// @Title: 用两个栈实现队列 (用两个栈实现队列 LCOF)
// @Author: Singularity0909
// @Date: 2020-06-24 05:01:34
// @Runtime: 664 ms
// @Memory: 103.4 MB

class CQueue {
public:
    stack<int> s1, s2;

    CQueue() {
        
    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if (s1.empty() && s2.empty())
            return -1;
        if (s2.size()) {
            int value = s2.top();
            s2.pop();
            return value;
        }
        while (s1.size()) {
            s2.push(s1.top());
            s1.pop();
        }
        int value = s2.top();
        s2.pop();
        return value;
    }
};
