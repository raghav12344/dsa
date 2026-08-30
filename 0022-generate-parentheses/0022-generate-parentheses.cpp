class Solution {
public:
    void recur(vector<string> &res,string temp,int n,int open)
    {
        if(temp.size()==2*n)
        {
            res.push_back(temp);
            return ;
        }
        if(open<n)
            recur(res,temp+'(',n,open+1);
        if(temp.size()-open<open)
            recur(res,temp+')',n,open);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        recur(res,"",n,0);
        return res;
    }
};