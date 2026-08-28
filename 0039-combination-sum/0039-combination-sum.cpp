class Solution {
public:
    void recur(vector<int>& candidates, int target,vector<vector<int>> &res,vector<int>arr,int i)
    {
        if(0==target)
        {
            res.push_back(arr);
            return;
        }
        if(i>=candidates.size() || target<0)
            return;

        arr.push_back(candidates[i]);
        recur(candidates,target-candidates[i],res,arr,i); //not chosing i;
        arr.pop_back();
        recur(candidates,target,res,arr,i+1);  // chosing i again;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> arr;
        vector<vector<int>> res;
        recur(candidates,target,res,arr,0);
        return res;
    }
};