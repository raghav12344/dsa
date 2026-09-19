// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s=0;
        int e=n;

        while(s<=e)
        {
            int m=s+(e-s)/2;

            if(!isBadVersion(m))
                s=m+1;
            else 
                e=m-1;
        }
        return s;
    }
};