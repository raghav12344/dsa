class Solution {
public:
    bool isSafe(vector<vector<char>> &m,int i,int j,int num)
    {
        int ch='0'+num;
        for(int x=0;x<9;x++)
        {
            if(m[x][j]==ch)
                return false;
        }
        for(int x=0;x<9;x++)
        {
            if(m[i][x]==ch)
                return false;
        }
        int si=i-i%3,sj=j-j%3;

        for(int r=0;r<3;r++)
        {
            for(int c=0;c<3;c++)
            {
                if(m[si+r][sj+c]==ch)
                    return false;
            }
        }
        return true;
    }
    bool recur(vector<vector<char>> & m,int i,int j)
    {
        if(i==8 && j==9)
            return true;
        
        if(j==9)
        {
            i++;
            j=0;
        }

        if(m[i][j]!='.')
            return recur(m,i,j+1);
        
        for(int num=1;num<=9;num++)
        {
            if(isSafe(m,i,j,num))
            {
                m[i][j]='0'+num;
                if(recur(m,i,j+1))
                    return true;
                m[i][j]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        recur(board,0,0);
    }
};