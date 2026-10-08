class Solution {
public:
    string removeOuterParentheses(string s) {
        string res="";
        int opened=0;
        for(char c:s)
        {
            if(c==')')
                opened--;
            if(opened)
                res.push_back(c);
            if(c=='(')
                opened++;
        }
        return res;
    }
};