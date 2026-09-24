class Solution {
public:
    int digsum(int n)
    {
        int sum=0;
        while(n!=0)
        {
            int r=n%10;
            sum+=r;
            n=n/10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(digsum(nums[i])==i)
                return i;
        }
        return -1;
    }
};