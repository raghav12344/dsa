class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int mod=1e9+7;
        int count=0;
        int psum=0;
        int oc=0;
        int ec=1;
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