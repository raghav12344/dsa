class Solution {
public:
bool chk(string &str, int l, int r)
{
    if (l == r)
        return true;
    
    vector<int> hash(256, 0); // initialize with 0 instead of -1
    for (int i = l; i <= r; i++)
    {
        hash[str[i]]++;
        if (hash[str[i]] > 1)
            return false;
    }
    return true;
}

int lengthOfLongestSubstring(string s)
{
    int mx = 0; // initialize mx = 0, not INT_MIN
    int l = 0, r = 0;
    while (r < s.length())
    {
        if (chk(s, l, r))
        {
            mx = max(mx, r - l + 1);
            r++; // only move r when current substring is valid
        }
        else
        {
            l++; // move left to shrink window
        }
    }
    return mx;
}
// int lengthOfLongestSubstring(string s)
// {
//     int mx = 0;
//     int l = 0, r = 0;
//     set<char> st;
    
//     while (r < s.length())
//     {
//         if (st.find(s[r]) == st.end())
//         {
//             // Character not in set, insert it
//             st.insert(s[r]);
//             mx = max(mx, r - l + 1);
//             r++;
//         }
//         else
//         {
//             // Character already exists, remove from left
//             st.erase(s[l]);
//             l++;
//         }
//     }
    
//     return mx;
// }


};