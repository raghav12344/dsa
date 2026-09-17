class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();

        vector<int> dp(n,-1);

        int l=0;
        int sum=0;
        int ans=1e9;
        int minlen=1e9;

        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            while(sum>target)
                sum-=arr[l++];
            
            if(sum==target)
            {
                int len=i-l+1;
                if(len>0 && dp[len-1]!=-1)
                    ans=min(ans,len+dp[l-1]);
                minlen=min(len,minlen);
            }
            dp[i]=minlen;
        }
        return ans==1e9?-1:ans;
    }
};