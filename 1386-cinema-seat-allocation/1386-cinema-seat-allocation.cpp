class Solution {
public:
    
    bool isempty1(vector<int>&seating)
    {
        if(seating[2] && seating[3] && seating[4] && seating[5])
            return true;
        else
            return false;
    }

    bool isempty2(vector<int>&seating)
    {
        if(seating[4] && seating[5] && seating[6] && seating[7])
            return true;
        else
            return false;
    }
    bool isempty3(vector<int>&seating)
    {
        if(seating[6] && seating[7] && seating[8] && seating[9])
            return true;
        else
            return false;
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int, vector<int>> seating;

        for(int i = 0; i < reservedSeats.size(); i++)
        {
            int row = reservedSeats[i][0];
            int col = reservedSeats[i][1];

            if(seating.find(row) == seating.end())
            seating[row] = vector<int>(11, 1);

            seating[row][col] = 0;
        }
        int count=0;
        count+=(long long)(n-seating.size())*2;
        for(auto &x:seating)
        {
            vector<int> &row=x.second;
            if(isempty1(row)&&isempty3(row))
                count+=2;
            else if(isempty1(row)||isempty2(row)||isempty3(row))
                count+=1;
            else 
                count+=0;
        }
        return count;
    }
};