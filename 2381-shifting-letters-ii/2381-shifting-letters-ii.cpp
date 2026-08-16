class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> diff(s.size()+1,0);

        for(int i=0;i<shifts.size();i++)
        {
            int start=shifts[i][0];
            int end=shifts[i][1];
            int val=(shifts[i][2]==1)?1:-1;

            diff[start]+=val;
            diff[end+1]-=val;
        }

        int curr_shift=0;
        for(int i=0;i<s.size();i++)
        {
            curr_shift+=diff[i];

            int net_shift=((curr_shift%26)+26)%26;

            s[i]='a'+(s[i]+net_shift-'a')%26;
        }
        return s;
    }
};
