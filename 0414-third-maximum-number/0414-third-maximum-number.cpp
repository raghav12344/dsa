class Solution {
public:
    int thirdMax(vector<int>& arr) {
        long long f=LLONG_MIN,s=LLONG_MIN,t=LLONG_MIN;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>f)
            {
                t=s;
                s=f;
                f=arr[i];
            }
            else if(arr[i]>s && arr[i]!=f)
            {
                t=s;
                s=arr[i];
            }
            else if(arr[i]>t && arr[i]!=s && arr[i]!=f)
                t=arr[i];
        }
        if(t==LLONG_MIN)
            return f;
        else 
            return t;
    }
};