class Solution {
public:
    void recur(vector<int>& candidates, int target,vector <vector<int>> &res,vector<int>arr,int i)
    {
        if(0==target)
        {
            res.push_back(arr);
            return;
        }
        if(i>=candidates.size() || target<0)
            return;

        arr.push_back(candidates[i]);
        recur(candidates,target-candidates[i],res,arr,i+1); 
        arr.pop_back();
        int j=i+1;
        while(j<candidates.size() && candidates[j]==candidates[i])
            j++;
        recur(candidates,target,res,arr,j);  
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> arr;
        vector<vector<int>> res;
        recur(candidates,target,res,arr,0);
        return res;
    }
};