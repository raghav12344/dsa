class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total=0;
        for(auto v:nums)
            total+=v;
        
        int target=total-x;

        if(target<0)
            return -1;
        if(target==0)
            return nums.size();

        int l=0;
        int sum=0;
        int longest=-1;

        for(int r=0;r<nums.size();r++)
        {
            sum+=nums[r];

            while(sum>target)
            {
                sum-=nums[l];
                l++;
            }
            if(sum==target)
                longest=max(longest,r-l+1);
        }
        if(longest==-1)
            return -1;
        
        return nums.size()-longest;
    }
};