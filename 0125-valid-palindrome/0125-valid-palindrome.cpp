class Solution {
public:
    bool isPalindrome(string s) {
        string t="";
        for(auto ch:s)
        {
            if((ch>='0' && ch<='9'))
            t+=ch;
            else if((ch>='a' && ch<='z') ||(ch>='A' && ch<='Z'))
            t+=tolower(ch);
        }
        string t1=t;
        reverse(t1.begin(),t1.end());
        if(t1==t)
            return true;
        return false;
    }
};