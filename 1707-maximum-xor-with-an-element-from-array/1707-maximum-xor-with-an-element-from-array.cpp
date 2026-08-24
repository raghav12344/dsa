class Trie{
public:
    Trie *child[2];
    Trie(){
        for(int i=0;i<2;i++)
            child[i]=NULL;
    }
    void insert(int num)
    {
        Trie *curr=this;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;

            if(curr->child[bit]==NULL)
                curr->child[bit]=new Trie();
            
            curr=curr->child[bit];
        }
    }
    int getmaxXor(int num)
    {
        Trie *curr=this;
        int ans=0;
        for(int i=31;i>=0;i--)
        {
            int b=(num>>i)&1;

            if(curr->child[1-b]!=NULL)
            {
                ans|=1<<i;
                curr=curr->child[1-b];
            }
            else
                curr=curr->child[b];
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());

        vector<pair<int,int>> order;

        for(int i=0;i<queries.size();i++)
            order.push_back({queries[i][1],i});
        
        sort(order.begin(),order.end());

        vector<int> ans(queries.size());

        int j=0;
        Trie *root=new Trie();
        for(auto[m,index]:order)
        {
            while(j<nums.size()&&nums[j]<=m)
            {
                root->insert(nums[j]);
                j++;
            }
            if(j==0)
                ans[index]=-1;
            else
                ans[index]=root->getmaxXor(queries[index][0]);
        }
        return ans;
    }
};