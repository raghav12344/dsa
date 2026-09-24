class Solution {
public:
    void recur(vector<int> &res,int n)
    {
        if(n==0)
            return ;
        int r=n%10;
        recur(res,n/10);
        res.push_back(r);

    }
    void adddig(vector<int> &res,int n)
    {
        recur(res,n);
    }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            adddig(res,nums[i]);
        }
        return res;
    }
};