class Solution {
public:
    void recur(vector<string> & res,string temp,string &num,int & target,int idx,long long val,long long last)
    {
        if(idx==num.length())
        {
            if(target==val)
            {
                res.push_back(temp);
                return ;
            }
            
        }
        for(int i=idx;i<num.size();i++)
        {
            if(idx!=i && num[idx]=='0')
                break;
            
            string part=num.substr(idx,i-idx+1);

            long long a=stoll(part);
            if(idx==0)
                recur(res,temp+part,num,target,i+1,a,a);
            else
            {
                recur(res,temp+"+"+part,num,target,i+1,val+a,a);
                recur(res,temp+"-"+part,num,target,i+1,val-a,-a);
                recur(res,temp+"*"+part,num,target,i+1,val-last+(last*a),last*a);
            }
        }


    }
    vector<string> addOperators(string num, int target) {
        vector<string>res;
        recur(res,"",num,target,0,0,0);
        return res;
    }
};