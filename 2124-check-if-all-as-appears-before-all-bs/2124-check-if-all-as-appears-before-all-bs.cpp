class Solution {
public:
    bool checkString(string s) {
        int idx=find(s.begin(),s.end(),'b')-s.begin();
        for(int i=idx;i<s.size();i++)
        {
            if(s[i]=='a')
                return false;
        }
        return true;
    }
};