
// @Title: 队列的最大值 (队列的最大值 LCOF)
// @Author: Singularity0909
// @Date: 2020-07-21 17:54:40
// @Runtime: 276 ms
// @Memory: 47.6 MB

class MaxQueue {
public:
    queue<int> a;
    deque<int> b;

    MaxQueue() {}
    
    int max_value()
    {
        return a.empty() ? -1 : b.front();
    }
    
    void push_back(int value)
    {
        a.push(value);
        while (!b.empty() && value > b.back()) {
            b.pop_back();
        }
        b.push_back(value);
    }
    
    int pop_front()
    {
        if (a.empty()) return -1;
        int x = a.front();
        a.pop();
        while (!b.empty() && b.front() == x) {
            b.pop_front();
        }
        return x;
    }
};
