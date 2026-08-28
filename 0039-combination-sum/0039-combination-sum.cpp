class Solution {
public:
    void recur(vector<int>& candidates, int target,vector<vector<int>> &res,vector<int>arr,int i,int sum)
    {
        if(i>=candidates.size())
            return;
        if(sum>target)
            return ;
        if(sum==target)
        {
            res.push_back(arr);
            return;
        }

        recur(candidates,target,res,arr,i+1,sum); //not chosing i;
        arr.push_back(candidates[i]);
        recur(candidates,target,res,arr,i,sum+candidates[i]);  // chosing i again;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> arr;
        vector<vector<int>> res;
        recur(candidates,target,res,arr,0,0);
        return res;
    }
};