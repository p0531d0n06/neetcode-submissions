class MinStack {
public:
    stack<int> s;
    stack<int> s_min;

    MinStack() {
    }
    
    void push(int val) {
        s.push(val);
        if(s_min.empty()) s_min.push(val);
        else s_min.push(min(s_min.top(), val));
    }
    
    void pop() {
        if(s.empty()) return;
        s.pop();
        s_min.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return s_min.top();
    }
};
