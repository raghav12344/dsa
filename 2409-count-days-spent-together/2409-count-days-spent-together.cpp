class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int days[]={0,0,31,59,90,120,151,181,212,243,273,304,334};
        int aa=days[stoi(arriveAlice.substr(0,2))]+stoi(arriveAlice.substr(3,2));
        int la=days[stoi(leaveAlice.substr(0,2))]+stoi(leaveAlice.substr(3,2));

        int ab=days[stoi(arriveBob.substr(0,2))]+stoi(arriveBob.substr(3,2));
        int lb=days[stoi(leaveBob.substr(0,2))]+stoi(leaveBob.substr(3,2));

        int arr[366]={0};
        for(int i=aa;i<=la;i++)
            arr[i]++;
        for(int i=ab;i<=lb;i++)
            arr[i]++;

        int count=0;
        for(int i=1;i<366;i++)
            if(arr[i]==2)
                count++;
            
        return count;

    }
};