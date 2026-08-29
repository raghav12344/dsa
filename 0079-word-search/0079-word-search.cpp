class Solution {
public:
    bool recur(vector<vector<char>>& board,string word,int i,int j,int k)
    {
        if(k==word.length())
            return true;
        if(i<0||j<0||i>=board.size()||j>=board[0].size())
            return false;
        
        if(board[i][j]==word[k])
        {
            char temp=board[i][j];
            board[i][j]='#';
            bool res=(recur(board,word,i+1,j,k+1)||recur(board,word,i-1,j,k+1)||recur(board,word,i,j+1,k+1)||recur(board,word,i,j-1,k+1));
            board[i][j]=temp;
            return res;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();

        if(word.length()>n*m)
            return false;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                    if(recur(board,word,i,j,0))
                        return true;
            }
        }
        return false;
    }
};