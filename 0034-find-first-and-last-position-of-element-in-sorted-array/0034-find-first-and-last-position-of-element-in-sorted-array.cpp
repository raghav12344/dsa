class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector <int> ans(2,-1);
        int l=0,r=nums.size()-1;
        int r1=r;
        if(r==0)
        {
            if(nums[0]==target)
            {
                ans[0]=0;
                ans[1]=0;
                return ans;
            }
        }
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(nums[mid]==target)
            {   
                ans[0]=mid;
                r=mid-1;
            }
            else if(nums[mid]<target)
                l=mid+1;
            else
                r=mid-1;
        }
        l=0;
        r=r1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(nums[mid]==target)
            {
                ans[1]=mid;
                l=mid+1;
            }
            else if(nums[mid]<target)
                l=mid+1;
            else
                r=mid-1;
        }
        return ans;
    }
};