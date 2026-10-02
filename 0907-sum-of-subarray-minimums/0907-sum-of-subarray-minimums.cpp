class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> left(arr.size(),0);
        vector<int> right(arr.size(),0);
        stack<int> st;

        for(int i=0;i<arr.size();i++)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
                st.pop();
            
            left[i]=st.empty()?i+1:i-st.top();
            st.push(i);
        }

        while(!st.empty())
            st.pop();

        for(int i=arr.size()-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
                st.pop();
            right[i]=st.empty()?arr.size()-i:st.top()-i;
            st.push(i);
        }

        int sum=0;
        int mod=1e9+7;
        for(int i=0;i<arr.size();i++)
            sum=(sum+(1LL*arr[i]*left[i]*right[i]))%mod;
        return sum;
    }
};