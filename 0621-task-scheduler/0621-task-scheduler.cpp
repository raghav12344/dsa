class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);

        for(auto ch:tasks)
            freq[ch-'A']++;

        sort(freq.begin(),freq.end());

        int mxfreq=freq[25]-1;

        int idle=mxfreq*n;

        for(int i=24;i>=0 && freq[i]>0;i--)
            idle-=min(mxfreq,freq[i]);

        return idle>0?idle+tasks.size():tasks.size();
    }
};