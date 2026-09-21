class Solution {
public:
    int findComplement(int num) {
        int ans=0;
        int base=0;
        while(num>0)
        {
            int b=num&1;
            if(b==0)
                ans+=pow(2,base);
            base++;
            num=num>>1;
        }
        return ans;
    }
};