class Solution {
public:
    vector<int> getRow(int rowIndex){
        rowIndex++;
        vector<vector<int>> pt;
        if(rowIndex>0)
            pt.push_back(vector<int>(1,1));
        if(rowIndex>1)
            pt.push_back(vector<int>(2,1));

        for(int i=2;i<rowIndex;i++)
        {
            vector<int> arr(i+1,1);
            for(int j=1;j<i;j++)
            {
                arr[j]=pt[i-1][j]+pt[i-1][j-1];
            }
            pt.push_back(arr);
        }
        return pt[rowIndex-1];
    }
};