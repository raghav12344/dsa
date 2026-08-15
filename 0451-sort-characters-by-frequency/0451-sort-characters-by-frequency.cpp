class Solution {
public:

    static bool cmp(pair<char,int>a,pair<char,int>b)
    {
        return a.second>b.second;
    } 
    string frequencySort(string s) {
        map<char,int> mp;
        for(auto ch:s)
            mp[ch]++;
        vector<pair<char,int>>arr;
        for(auto &it:mp)
            arr.push_back(it);
        
        sort(arr.begin(),arr.end(),cmp);
        
        string res="";
        for(auto pr:arr)
        {
            for(int i=pr.second;i>0;i--)
                res+=pr.first;
        }
        return res;
    }
};