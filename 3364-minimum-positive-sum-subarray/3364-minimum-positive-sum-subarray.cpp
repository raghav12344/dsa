class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int mn=INT_MAX;
        for(int i=l;i<=r;i++)
        {
            int sum=0;
            for(int j=0;j<i;j++)
                sum+=nums[j];
            if(sum>0)
                mn=min(mn,sum);
            
            for(int j=i;j<nums.size();j++)
            {
                sum+=nums[j];
                sum-=nums[j-i];
                if(sum>0)
                    mn=min(mn,sum);
            }
        }
        return mn==INT_MAX?-1:mn;
    }
};