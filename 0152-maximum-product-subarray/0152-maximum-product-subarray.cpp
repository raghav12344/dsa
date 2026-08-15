class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int i=1,j=1;

        int mx=INT_MIN;

        for(int k=0;k<nums.size();k++)
        {
            if(i==0)
                i=1;
            if(j==0)
                j=1;
            
            i*=nums[k];
            j*=nums[nums.size()-1-k];
            mx=max({i,j,mx});
        }
        return mx;
    }
};