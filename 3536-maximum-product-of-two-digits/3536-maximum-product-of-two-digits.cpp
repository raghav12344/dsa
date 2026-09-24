class Solution {
public:
    int maxProduct(int n) {
        priority_queue<int> pq;
        while(n!=0)
        {
            int r=n%10;
            n=n/10;
            pq.push(r);
        }
        int res=1;
        if(!pq.empty())
            res*=pq.top();
        pq.pop();
        if(!pq.empty())
            res*=pq.top();

        pq.pop();
        return res;
    }

};