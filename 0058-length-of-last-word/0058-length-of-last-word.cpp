class Solution {
public:
    int lengthOfLastWord(string s) {
        int j=s.size()-1;
        int len=0;
        while(j>=0)
        {
            if(s[j]==' ')
                j--;
            else 
                break;
        }
        while(j>=0)
        {
            if(s[j]==' ')
                break;
            j--;
            len++;
        }
        return len;
    }
};