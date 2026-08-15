class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pt;
        if(numRows>0)
            pt.push_back(vector<int>(1,1));
        if(numRows>1)
            pt.push_back(vector<int>(2,1));

        for(int i=2;i<numRows;i++)
        {
            vector<int> arr(i+1,1);
            for(int j=1;j<i;j++)
            {
                arr[j]=pt[i-1][j]+pt[i-1][j-1];
            }
            pt.push_back(arr);
        }
        return pt;

    }
};