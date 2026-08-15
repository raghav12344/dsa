class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int mx=0;
        for(auto ch:s)
        {
            if(ch=='(')
            st.push(ch);

            else if(ch==')')
            st.pop();

            mx=max(mx,(int)st.size());
        }
        return mx;
    }
};