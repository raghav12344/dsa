class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> count(26,0);
        for(char c:s)
            count[c-'a']++;

        int i=0;
        int n=s.size();
        while(i<s.size() && count[target[i]-'a']>0)
        {
            count[target[i]-'a']--;
            i++;
        }
        if(i==n)
        {
            i--;
            count[target[i]-'a']++;
        }


        for(int j=i;j>=0;j--)
        {
            int t_idx=target[j]-'a';

            for(int c=t_idx+1;c<26;c++)
            {
                if(count[c]>0)
                {
                    string res=target.substr(0,j);
                    res+=char(c+'a');
                    count[c]--;
                    for(int k=0;k<26;k++)
                    {
                        if(count[k]>0)
                            res.append(count[k],(char)(k+'a'));
                    }
                    return res;
                }
            }
            if(j>0)
                count[target[j-1]-'a']++;

        }
        return "";
    }
};