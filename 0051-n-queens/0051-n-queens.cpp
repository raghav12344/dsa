class Solution {
public:
    vector<vector<string>> ans;
    bool isSafe(vector<string> &m,int i,int j)
    {
        for(int r=0;r<i;r++)
        {
            if(m[r][j]=='Q')
                return false;
        }
        for(int r=i-1,c=j-1;r>=0 && c>=0;r--,c--)
        {
            if(m[r][c]=='Q')
                return false;
        }
        for(int r=i-1,c=j+1;r>=0 && c<m.size();r--,c++)
        {
            if(m[r][c]=='Q')
                return false;
        }
        return true;
    }
    void recur(vector<string> &m,int i)
    {
        if(i==m.size())
        {    
            ans.push_back(m);
            return ;
        }
        
        for(int col=0;col<m.size();col++)
        {
            if(isSafe(m,i,col))
            {
                m[i][col]='Q';
                recur(m,i+1);
                m[i][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        recur(board,0);
        return ans;
    }
};