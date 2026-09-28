class Solution {
public:
    int chk(vector<int> &arr,int mid)
    {
        int days=1;
        int sum=0;
        for(int i=0;i<arr.size();i++)
        {
            if(sum+arr[i]<=mid)
                sum+=arr[i];
            else 
            {
                days++;
                sum=arr[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int s=*max_element(weights.begin(),weights.end());
        int e=0;
        for(auto v:weights)
            e+=v;
        int ans=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;

            if(chk(weights,mid)<=days)
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