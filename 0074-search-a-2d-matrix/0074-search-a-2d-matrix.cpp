class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int s=0;
        int e=matrix.size()-1;
        while(s<e)
        {
            int mid=s+(e-s)/2;
            
            if(target>=matrix[mid][0])
                s=mid+1;
            else
                e=mid;
        }
        if(target<matrix[s][0])
        {
            if(s==0)
                return false;
            s--;
        }
        int i=0;
        int j=matrix[0].size()-1;

        while(i<=j)
        {
            int mid=i+(j-i)/2;

            if(matrix[s][mid]==target)
                return true;
            else if(matrix[s][mid]>target)
                j=mid-1;
            else 
                i=mid+1;
        }
        return false;
        
    }
};