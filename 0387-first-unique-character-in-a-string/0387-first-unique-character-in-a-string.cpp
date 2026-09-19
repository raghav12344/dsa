class Solution {
public:
    int firstUniqChar(string s) {
        for(int i=0;i<s.size();i++)
        {
            if(find(s.begin(),s.begin()+i,s[i])==s.begin()+i && find(s.begin()+i+1,s.end(),s[i])==s.end())
                return i;
        }
        return -1;
    }
};