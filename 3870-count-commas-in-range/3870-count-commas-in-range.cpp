class Solution {
public:
    int countCommas(int n) {
        if(n<=999)
            return 0;
        else if(n==pow(10,5))
            return (n-999);
        else
            return (n-999);
    }
};