class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int> arr;
        for(int i=cardPoints.size()-k;i<cardPoints.size();i++)
        {
            arr.push_back(cardPoints[i]);
        }
        for(int i=0;i<k;i++)
        {
            arr.push_back(cardPoints[i]);
        }
        int i=0;
        int j=k-1;
        int sum=0;
        for(int i=0;i<=j;i++)
            sum+=arr[i];
        int mx=sum;
        while(j<arr.size()-1)
        {
            sum-=arr[i];
            i++;
            j++;
            sum+=arr[j];
            mx=max(sum,mx);
        }
        return mx;
    }
};