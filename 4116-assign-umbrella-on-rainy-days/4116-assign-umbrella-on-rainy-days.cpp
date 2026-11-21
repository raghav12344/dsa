class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        vector<string> res(rain.size(),"None");
        int counta=0;
        int countb=0;
        for(int i=0;i<rain.size();i++)
        {
            int na=(i<rain.size()-1 && rain[i]==rain[i+1]);
            int nb=(rain[i]==1);

            if(na && nb)
            {
                if(counta<=countb)
                {
                    res[i]="Alice";
                    counta++;
                }
                else 
                {
                    res[i]="Bob";
                    countb++;
                }
            }
            else if(nb)
            {
                res[i]="Bob";
                countb++;
            }       
        }
        return res;
    }
};