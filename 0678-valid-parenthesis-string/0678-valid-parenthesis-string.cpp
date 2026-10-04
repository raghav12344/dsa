class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open;
        stack<int> star;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                open.push(i);
            else if(s[i]=='*')
                star.push(i);
            else 
            {
                if(!open.empty())
                    open.pop();
                else if(!star.empty())
                    star.pop();
                else 
                    return false;
            }
        }
        while(!open.empty() && !star.empty())
        {
            if(open.top()>star.top())
                return false;
            
            open.pop();
            star.pop();
        }
        return open.empty();

        // int open=0;
        // int close=0;

        // for(int i=0;i<s.size();i++)
        // {
        //     if(s[i]=='(' || s[i]=='*')
        //         open++;
        //     else
        //         open--;
            
        //     if(s[s.size()-i-1]==')' || s[s.size()-i-1]=='*')
        //         close++;
        //     else 
        //         close--;
            
        //     if(open<0 || close<0)
        //         return false;
        // }
        // return true;
    }
};