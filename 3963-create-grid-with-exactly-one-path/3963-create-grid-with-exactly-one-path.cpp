class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid;
        string temp="";
        for(int i=0;i<n;i++)
        {
            temp+='.';
        }
        grid.push_back(temp);
        for(int k=1;k<m;k++)
        {
            temp="";
            for(int i=0;i<n;i++)
            {
                if(i==n-1)
                    temp+='.';
                else 
                    temp+='#';
            }
            grid.push_back(temp);
        }
        return grid;
    }
};