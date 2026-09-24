class Solution {
public:
    int maximumLengthSubstring(string s) {
        int res=0;
        vector<int> freq(26,0);
        for(int l=0,r=0;r<s.size();r++)
        {
            freq[s[r]-'a']++;

            while(freq[s[r]-'a']>2)
            {
                freq[s[l]-'a']--;
                l++;
            }
            res=max(res,r-l+1);
        }
        return res;
    }
};