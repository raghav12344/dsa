class Solution {
public:
    bool sumGame(string num) {
        int diff=0;
        int qleft=0,qright=0;

        for(int i=0;i<num.size()/2;i++)
        {
            if(num[i]=='?')
                qleft++;
            else
                diff+=num[i]-'0';
        }

        for(int i=num.size()/2;i<num.size();i++)
        {
            if(num[i]=='?')
                qright++;
            else
                diff-=num[i]-'0';
        }
        if((qleft+qright)%2==1)
            return true;
        
        return diff!= 9*(qright-qleft)/2;
    }
};