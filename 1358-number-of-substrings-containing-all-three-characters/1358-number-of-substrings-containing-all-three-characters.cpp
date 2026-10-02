class Solution {
public:
    bool istrue(vector<int> & freq)
    {
        return freq[0]&&freq[1]&&freq[2];
    }
    int numberOfSubstrings(string s) {
        int i=0;
        int ans=0;
        vector<int> freq(3,0);
        for(int j=0;j<s.size();j++)
        {
            char ch=s[j];
            freq[ch-'a']++;

            while(istrue(freq))
            {
                ans+=s.size()-j;
                char chl=s[i];
                freq[chl-'a']--;
                i++;
            }
        }
        return ans;
    }
};