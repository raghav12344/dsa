class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);
        int cost=0;
        for(auto ch:word)
        {
           freq[ch-'a']++;
        }
        sort(freq.rbegin(),freq.rend());

        for(int i=0;i<26;i++)
        {
            if(freq[i]==0)
                break;
            int push=i/8+1;
            cost+=freq[i]*push;
        }
        return cost;


    }
};