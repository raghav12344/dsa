class Solution {
public:
    bool chk(vector<int> arr,int mid,int k)
    {
        int count=1;
        int sum=0;
        for(int i=0;i<arr.size();i++)
        {
            if(sum+arr[i]<=mid)
                sum+=arr[i];
            else
            {
                if(arr[i]>mid)
                    return false;
                count++;
                sum=arr[i];
            }
        }
        return count<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int s=0;
        int e=1e9;
        int ans=0;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(chk(nums,mid,k))
            {
                ans=mid;
                e=mid-1;
            }
            else
                s=mid+1;
        }
        return ans;
    }
};