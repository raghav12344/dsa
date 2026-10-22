class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 0;
        
        int s=find(nums.begin(),nums.end(),0)-nums.begin();

        bool asc=true;
        bool desc=true;
        for(int i=1;i<n;i++)
        {
            int v=nums[(s+i)%n];
            if(v!=i)
                asc=false;
            if(v!=n-i)
                desc=false;
            
            if(!asc && !desc)
                return -1;
        }
        if(asc)
            return min(s,n-s+2);
        return min(n-s,s+2);
    }
};