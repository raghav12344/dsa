class Solution {
public:
    void revrs(stack<char> &stk)
    {
        string temp="";

        while(stk.top()!='(')
        {
            temp+=stk.top();
            stk.pop();
        }
        stk.pop();
        
        for(auto ch:temp)
            stk.push(ch);
    }
    string reverseParentheses(string s) {
        stack<char> stk;

        for(auto ch:s)
        {
            if(ch==')')
            {
                revrs(stk);
            }
            else 
            {
                stk.push(ch);
            }
        }
        string res="";
        while(!stk.empty())
        {
            res+=stk.top();
            stk.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};