class Solution {
public:
    vector<int> nums;
    int mergeSort(int s,int e)
    {
        if(s>=e)
            return 0;
        
        int mid=s+(e-s)/2;

        return mergeSort(s,mid)+mergeSort(mid+1,e)+merge(s,mid,e);
        
    }
    int merge(int s,int mid,int e)
    {
        int count=0,j=mid+1;
        for(int i=s;i<=mid;i++)
        {
            while(j<=e && nums[i]>2LL * nums[j])
                j++;
            count+=(j-(mid+1));
        }
        vector<int> temp;
        int left=s;
        int right=mid+1;
        while(left<=mid && right<=e)
        {
            if(nums[left]<nums[right])
                temp.push_back(nums[left++]);
            else
                temp.push_back(nums[right++]);
        }
        while(left<=mid)
            temp.push_back(nums[left++]);
        while(right<=e)
            temp.push_back(nums[right++]);
        for(int i=s;i<=e;i++)
            nums[i]=temp[i-s];

        return count;
    }
    int reversePairs(vector<int>& arr) {
        nums=arr;
        return mergeSort(0,arr.size()-1);
    }
};