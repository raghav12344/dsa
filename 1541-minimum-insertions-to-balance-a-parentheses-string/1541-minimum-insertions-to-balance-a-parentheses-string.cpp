class Solution {
public:
    int minInsertions(string s) {
        int open=0;
        int ans=0;
        for(auto ch:s)
        {
            if(ch=='(')
            {
                if(open%2==1)
                {
                    ans++;
                    open--;
                }
                open+=2;
            }
            if(ch==')')
            {
                open--;
                if(open<0)
                {
                    open=1;
                    ans++;
                }
            }
        }
        return open+ans;
    }
};