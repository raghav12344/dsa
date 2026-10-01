class Solution {
public:
    int beautySum(string s) {
        int sum=0;
        for(int i=0;i<s.size();i++)
        {
            vector<int> freq(26,0);
            for(int j=i;j<s.size();j++)
            {
                freq[s[j]-'a']++;
                int mx=INT_MIN,mn=INT_MAX;
                for(int ch=0;ch<26;ch++)
                {
                    int diff=freq[ch];
                    if(diff>0)
                    {
                        mx=max(mx,diff);
                        mn=min(mn,diff);
                    }
                }
                sum+=(mx-mn);
            }
        }
        return sum;
    }
};