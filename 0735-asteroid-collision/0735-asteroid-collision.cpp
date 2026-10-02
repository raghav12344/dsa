class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto v:asteroids)
        {
            bool alive=true;
            while(!st.empty() && v<0 && st.top()>0)
            {
                if(st.top()<abs(v))
                    st.pop();
                else if(st.top()==abs(v))
                {
                    alive=false;
                    st.pop();
                    break;
                }
                else 
                {
                    alive=false;
                    break;
                }
            }
            if(alive)
                st.push(v);
            
        }
        vector<int> res;
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};