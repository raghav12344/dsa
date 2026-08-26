class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int l=0;
        int ones=0;
        int minLen=INT_MAX;
        string ans="";

        for(int r=0;r<s.size();r++)
        {
            if(s[r]=='1')
                ones++;
            while(ones>k)
            {
                if(s[l]=='1')
                    ones--;
                l++;
            }
            if(ones==k)
            {
                while(s[l]=='0')
                    l++;
                
                int len=r-l+1;

                string curr=s.substr(l,len);

                if(len<minLen)
                {
                    minLen=len;
                    ans=curr;
                }
                else if(len==minLen && curr<ans)
                    ans=curr;
            }
        }
        return ans;
    }
};