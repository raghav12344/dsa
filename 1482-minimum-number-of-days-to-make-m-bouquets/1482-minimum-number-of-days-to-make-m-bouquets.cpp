class Solution {
public:
    int chk(vector<int> arr,int mid,int k)
    {
        int count=0;

        int num=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]<=mid)
                count++;
            else 
                count=0;
            
            if(count==k)
            {
                num++;
                count=0;
            }
        }
        return num;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int s=0;
        int e=0;

        for(auto v:bloomDay)
            e=max(e,v);
        int ans=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;

            if(chk(bloomDay,mid,k)>=m)
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