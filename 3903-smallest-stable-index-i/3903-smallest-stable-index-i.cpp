class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefmax(n);
        vector<int> sufmin(n);

        prefmax[0]=nums[0];
        for(int i=1;i<n;i++)
            prefmax[i]=max(nums[i],prefmax[i-1]);
        
        sufmin[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--)
            sufmin[i]=min(nums[i],sufmin[i+1]);

        int score=INT_MAX;

        for(int i=0;i<n;i++)
        {
            int val=prefmax[i]-sufmin[i];
            if(val<=k)
                return i;
        }
        return -1;
    }
};