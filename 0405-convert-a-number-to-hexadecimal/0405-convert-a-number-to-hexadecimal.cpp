class Solution {
public:
    string toHex(int x) {
        unsigned int num=x;
        int n=0;
        for(int i=0;i<32;i++)
        {
            int b=num&1;
            num>>=1;
            n<<=1;
            n|=b;
        }
        string res="";
        for(int i=0;i<8;i++)
        {
            int temp=0;
            for(int i=0;i<4;i++)
            {
                int b=n&1;
                n>>=1;
                temp<<=1;
                temp|=b;
            }
            if(temp<=9)
                res+=(to_string(temp));
            else
                res+=('a'+temp-10);
        }
        int pos=0;
        while(pos<res.size()-1 && res[pos]=='0')
            pos++;
        return res.substr(pos);
    }
};