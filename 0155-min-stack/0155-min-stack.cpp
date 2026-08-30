class MinStack {
    stack<long long> st;
    long long mn;
public:

    MinStack() {
        mn=-1;
    }
    
    void push(int value) {
        if(st.empty())
        {
            mn=value;
            st.push(value);
        }
        else if(value<mn)
        {
            st.push(2LL*value-mn);
            mn=value;
        }
        else 
            st.push(value);
    }
    
    void pop() {
        if(st.empty())
            return;
        
        long long top=st.top();
        st.pop();

        if(top<mn)
            mn=2LL*mn-top;
    }
    
    int top() {
        if(st.empty())
            return -1;
        long long top=st.top();
        return (mn>top)?mn:top;
    }
    
    int getMin() {
        if(st.empty())
            return -1;
        return mn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */