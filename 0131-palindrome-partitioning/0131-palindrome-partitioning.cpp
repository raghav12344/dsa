class Solution {
public:
    bool isPalindrome(string s)
    {
        int i=0;
        int j=s.size()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void recur(string &s,vector<vector<string>> &res,int idx,int n,vector<string> &ans)
    {
        if(n==idx)
        {
            res.push_back(ans);
            return;
        }
        for(int i=idx;i<n;i++)
        {
            if(isPalindrome(s.substr(idx,i-idx+1)))
            {
                ans.push_back(s.substr(idx,i-idx+1));
                recur(s,res,i+1,n,ans);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> ans;
        recur(s,res,0,s.size(),ans);
        return res;
    }
};