class MyQueue {
public:
    stack<int> st;
    MyQueue() {
        
    }
    void push(int x) {
        if(st.empty())
        {
            st.push(x);
            return ;
        }

        int val=st.top();
        st.pop();
        push(x);
        st.push(val);
    }
    
    int pop() {
        if(!st.empty())
        {
            int val=st.top();
            st.pop();
            return val;
        }
        return -1;
    }
    
    int peek() {
        if(st.empty())
            return -1;
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */