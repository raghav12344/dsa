class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> st;

        for(auto v:arr)
            st.insert(v);
        map<int,int> mp;
        int r=1;
        for(auto v:st)
        {
            mp[v]=r;
            r++;
        }
        for(int i=0;i<arr.size();i++)
            arr[i]=mp[arr[i]];
        
        return arr;
    }
};