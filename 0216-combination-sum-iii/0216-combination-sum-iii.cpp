class Solution {
public:
    void recur(int i,vector<vector<int>>&res,vector<int>arr,int target,int k)
    {
        if(target==0 && arr.size()==k)
        {
            res.push_back(arr);
            return ;
        }
        if(i>9)
            return ;
        recur(i+1,res,arr,target,k);
        arr.push_back(i);
        recur(i+1,res,arr,target-i,k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if(n>45)
            return res;
        vector<int> arr;
        recur(1,res,arr,n,k);
        return res;
    }
};