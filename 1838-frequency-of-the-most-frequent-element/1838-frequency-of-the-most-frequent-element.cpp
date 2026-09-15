class Solution {
public:
    int maxFrequency(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        int start=0;
        int end=0;
        long long sum=0;
        int res=0;

        for(end=0;end<arr.size();end++)
        {
            sum+=arr[end];
            while((long long)(end-start+1)*arr[end]-sum>k)
            {
                sum-=arr[start];
                start++;
            }
            res=max(res,end-start+1);
        }
        return res;
    }
};