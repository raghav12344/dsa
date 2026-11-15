class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int mod=1e9+7;
        int count=0,psum=0,oc=0,ec=1;
        for(auto v:arr)
        {
            psum+=v;
            if(psum%2==0)
            {
                count+=oc;
                ec++;
            }
            else 
            {
                count+=ec;
                oc++;
            }
            count%=mod;
        }
        return count;
    }
};