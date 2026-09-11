class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10]={};

        for(auto d:digits)
        {
            freq[d]++;
        }

        int ans=0;

        for(int f=1;f<=9;f++)
        {
            for(int s=0;s<=9;s++)
            {
                for(int t=0;t<=8;t+=2)
                {
                    if(freq[f]==0 || freq[s]==0 || freq[t]==0)
                        continue;
                    if(f==s && s==t && freq[f]<3)
                        continue;
                    if(f==s && freq[f]<2)
                        continue;
                    if(f==t && freq[f]<2)
                        continue;
                    if(s==t && freq[s]<2)
                        continue;
                    
                    ans++;
                }
            }
        }
        return ans;
    }
};