class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res;
        int count=0;
        for(auto ch:seq)
        {
            if(ch=='(')
            {
                count++;
                res.push_back(count%2);
            }
            else 
            {
                res.push_back(count%2);
                count--;
            }
        }
        return res;
    }
};