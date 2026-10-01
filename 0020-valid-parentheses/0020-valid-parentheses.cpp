class Solution {
public:
    bool isValid(string s) {
        stack <char> stk;
        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];
            if(ch=='['|| ch=='{' ||ch=='(')
                stk.push(ch);
            else
            {
                if(stk.empty())
                    return false;
                char tp=stk.top();
                stk.pop();
                if(tp=='[' && ch==']'|| tp=='(' && ch==')' || tp=='{' && ch=='}')
                    continue;
                else
                    return false;
            }
        }
        if(stk.empty())
            return true;
        else
            return false;
    }
};