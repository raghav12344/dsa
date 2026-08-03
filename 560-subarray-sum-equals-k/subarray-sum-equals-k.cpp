class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int,int> prefix;
        int res=0;
        int currsum=0;
        for(auto val:nums)
        {
            currsum+=val;

            if(currsum==k)
                res++;
            
            if(prefix.find(currsum-k)!=prefix.end())
                res+=prefix[currsum-k];
            
            prefix[currsum]++;
        }
        return res;
    }
};