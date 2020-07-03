// Version 1
class CQueue {
public:
    stack<int> s1, s2;

    CQueue() {
        
    }
    
    void appendTail(int value) {
        while (s1.size()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(value);
        while (s2.size()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int deleteHead() {
        if (s1.empty())
            return -1;
        int value = s1.top();
        s1.pop();
        return value;
    }
};

// Version 2
class CQueue {
public:
    stack<int> s1, s2;

    CQueue() {
        
    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if (s1.empty())
            return -1;
        while (s1.size()) {
            s2.push(s1.top());
            s1.pop();
        }
        int value = s2.top();
        s2.pop();
        while (s2.size()) {
            s1.push(s2.top());
            s2.pop();
        }
        return value;
    }
};

// Version 3
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