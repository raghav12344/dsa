class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1;
        int h=*max_element(nums.begin(),nums.end());
        int ans=-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;

            int sum=0;
            for(int i=0;i<nums.size();i++)
            {
                int div=nums[i]/mid;
                int rem=nums[i]%mid;
                if(rem==0)
                    sum+=div;
                else 
                    sum+=div+1;
            }

            if(sum<=threshold)
            {
                ans=l;
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return l;
    }
};