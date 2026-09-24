class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res;
        for(auto s:words)
        {
            int w=0;
            for(auto ch:s)
                w+=weights[ch-'a'];
            w=w%26;

            res+='z'-w;
        }
        return res;
    }
};