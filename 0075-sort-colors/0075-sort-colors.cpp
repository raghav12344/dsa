class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3,0);
        int s=0;
        for(int i=0;i<nums.size();i++)
        {
            count[nums[i]]++;
        }
        if(count[0]!=0)
        {
            for(int i=0;i<count[0];i++)
            {
                nums[s]=0;
                s++;
            }

        }
        if(count[1]!=0)
        {
            for(int i=0;i<count[1];i++)
            {
                nums[s]=1;
                s++;
            }

        }
        if(count[2]!=0)
        {
            for(int i=0;i<count[2];i++)
            {
                nums[s]=2;
                s++;
            }

        }
    }
};