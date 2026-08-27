class Solution {
public:
    bool isSafe(int x,int y,int n,int m)
    {
        return (x>=0 && x<n && y>=0 && y<m);
    }
    void fill(int i,int j,vector<vector<char>>& board)
    {
        if(!isSafe(i,j,board.size(),board[0].size()))
            return ;
        
        if(board[i][j]!='-')
            return ;
        
        board[i][j]='O';

        fill(i+1,j,board);
        fill(i-1,j,board);
        fill(i,j+1,board);
        fill(i,j-1,board);
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(board[i][j]=='O')
                    board[i][j]='-';
        
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='-')
                fill(i,0,board);
            if(board[i][m-1]=='-')
                fill(i,m-1,board);
        }
        for(int j=0;j<m;j++)
        {
            if(board[0][j]=='-')
                fill(0,j,board);
            if(board[n-1][j]=='-')
                fill(n-1,j,board);
        }

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(board[i][j]=='-')
                    board[i][j]='X';
    }
};