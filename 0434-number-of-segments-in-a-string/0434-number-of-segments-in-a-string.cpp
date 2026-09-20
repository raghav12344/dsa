class Solution {
public:
    int countSegments(string s) {
        int count=0;
        int i=0;
        while(i<s.size() && s[i]==' ')
            i++;

        while(i<s.size())
        {
            if(s[i]!=' ')
            {
                count++;
                while(i<s.size() && s[i]!=' ')
                    i++;
            }
            else 
                i++;
        }
        return count;
    }
};