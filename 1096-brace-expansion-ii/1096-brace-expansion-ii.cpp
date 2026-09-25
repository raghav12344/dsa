class Solution {
public:
    set<string> st;
    void dfs(string s)
    {
        int r=s.find('}');
        if(r==-1)
        {
            st.insert(s);
            return ;
        }
        int l=s.rfind('{',r);
        string left=s.substr(0,l);
        string right=s.substr(r+1);

        string inside=s.substr(l+1,r-l-1);
        string p;
        stringstream ss(inside);
        while(getline(ss,p,','))
            dfs(left+p+right);
    }
    vector<string> braceExpansionII(string exp) {
        dfs(exp);
        vector<string> ans;
        for(auto s:st)
            ans.push_back(s);
        return ans;

    }
};