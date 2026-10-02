class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=0;
        int i=0;
        int sum=0;
        int z=0;
        for(int j=0;j<nums.size();j++)
        {
            sum+=nums[j];
            while(i<j&&sum>goal)
            {
                sum-=nums[i];
                i++;
                z=0;
            }
            if(sum==goal)
            {
                int k=i;
                z=0;
                while(k<=j && nums[k]==0)
                {
                    k++;
                    z++;
                }
                if(goal==0)
                    ans+=z;
                else 
                    ans+=z+1;
            }
            
        }
        return ans;
    }
};