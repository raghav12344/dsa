class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> lw(26);
        vector<bool> up(26);

        for(auto ch:word)
        {
            if(ch>='a' && ch<='z')
                lw[ch-'a']=true;
            else 
                up[ch-'A']=true;
        }
        int count=0;
        for(int i=0;i<26;i++)
        {
            if(lw[i]&&up[i])
                count++;
        }
        return count;
    }
};