class Trie{
public:
    Trie * child[2];
    Trie(){
        for(int i=0;i<2;i++)
            child[i]=NULL;
    }
    void insert(int n){
        Trie *curr=this;
        for(int i=31;i>=0;i--)
        {
            int bit=(n>>i)&1;

            if(curr->child[bit]==NULL)
                curr->child[bit]=new Trie;

            curr=curr->child[bit];
        }
    }
    int findXOR(int n){
        Trie *curr=this;

        int res=0;

        for(int i=31;i>=0;i--)
        {
            int bit=(n>>i)&1;

            if(bit==0)
            {
                if(curr->child[1])
                {
                    curr=curr->child[1];
                    res+=(1<<i);
                }
                else 
                    curr=curr->child[0];
            }
            else 
            {
                if(curr->child[0])
                {
                    curr=curr->child[0];
                    res+=(1<<i);
                }
                else 
                    curr=curr->child[1];
            }
        }
        return res;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res=0;
        Trie *t=new Trie();
        t->insert(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            res=max(res,t->findXOR(nums[i]));
            t->insert(nums[i]);
        }
        return res;
    }
};
