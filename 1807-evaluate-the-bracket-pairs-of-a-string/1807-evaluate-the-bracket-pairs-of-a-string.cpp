class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;

        for(auto pr:knowledge)
            mp[pr[0]]=pr[1];
        string res="";
        int i=0;
        while(i<s.size())
        {
            if(s[i]=='(')
            {
                int j=i+1;
                string rep="";
                while(j<s.size())
                {
                    if(s[j]==')')
                        break;
                    rep+=s[j];
                    j++;
                }
                

                if(mp.find(rep)!=mp.end())
                {
                    res+=mp[rep];
                }
                else
                {
                    res+='?';
                }
                i=j;
            }
            else 
            {
                res+=s[i];
            }
            i++;
        }
        return res;
        
    }
};