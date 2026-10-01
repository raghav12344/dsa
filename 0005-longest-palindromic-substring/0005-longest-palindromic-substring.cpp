class Solution {
public:
    string longestPalindrome(string s) {
        int start=0;
        int maxlen=1;
        for(int i=0;i<s.size();i++)
        {
            for(int j=0;j<=1;j++)
            {
                int lo=i;
                int hi=i+j;

                while(lo>=0 && hi<s.size() && s[lo]==s[hi])
                {
                    int len=hi-lo+1;
                    if(len>maxlen)
                    {
                        start=lo;
                        maxlen=len;
                    }
                    lo--;
                    hi++;
                }
            }
        }
        return s.substr(start,maxlen);
    }
};