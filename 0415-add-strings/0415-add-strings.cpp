class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.size()!=num2.size())
        {
            string temp="";
            for(int i=0;i<abs((int)num1.size()-(int)num2.size());i++)
            {
                temp+='0';
            }
            if(num1.size()<num2.size())
                num1=temp+num1;
            else 
                num2=temp+num2;
        }
        int carry=0;
        for(int i=num1.size()-1;i>=0;i--)
        {
            int a=num1[i]-'0';
            int b=num2[i]-'0';
            int res=a+b+carry;
            carry=(res)/10;
            num1[i]='0'+(res)%10;
        }
        if(carry>0)
            num1=to_string(carry)+num1;
        return num1;
    }
};