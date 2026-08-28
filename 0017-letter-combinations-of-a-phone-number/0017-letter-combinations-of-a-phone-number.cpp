class Solution {
public:
    void recur(string digits,int i,vector<string> & mp,int j,string temp,vector<string>&res)
    {
        if(i==digits.size())
        {
            res.push_back(temp);
            return;
        }
        
        string letters=mp[digits[i]-'0'];
        if(j==letters.size())
            return;
        
        recur(digits,i,mp,j+1,temp,res);

        temp+=letters[j];
        recur(digits,i+1,mp,0,temp,res);
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        vector<string> mp={
            "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };
        string temp;
        recur(digits,0,mp,0,temp,res);
        return res;
    }
};