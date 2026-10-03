class Solution {
public:
    // stack solution 
    // int longestValidParentheses(string s) {
    //     int ans=0;
    //     stack<int> st;
    //     st.push(-1);
    //     for(int i=0;i<s.size();i++)
    //     {
    //         if(s[i]=='(')
    //             st.push(i);
    //         else
    //         {
    //             st.pop();
    //             if(st.empty())
    //                 st.push(i);
    //             else
    //             ans=max(ans,i-st.top());
    //         }
    //     }
    //     return ans;
    // }

    //  dp solution 
    int longestValidParentheses(string s) {
        vector<int> dp(s.size(),0);
        int ans=0;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==')')
            {
                if(s[i-1]=='(')
                {
                    dp[i]=2;
                    if(i>2)
                        dp[i]+=dp[i-2];
                }
                else
                {
                    int j=i-dp[i-1]-1;
                    if(j>=0 && s[j]=='(')
                    {
                        dp[i]=dp[i-1]+2;
                        if(j>=1)
                            dp[i]+=dp[j-1];
                    }
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};