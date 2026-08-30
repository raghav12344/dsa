class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int idx1=max_element(nums.begin(),nums.end())-nums.begin();
        int idx2=min_element(nums.begin(),nums.end())-nums.begin();

        if(idx1>idx2)
            swap(idx1,idx2);
        
        int front=idx2+1;
        int back=n-idx1;
        int both=idx1+1+n-idx2;

        return min({front,back,both});
    }
};