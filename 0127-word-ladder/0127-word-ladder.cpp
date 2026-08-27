class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());

        queue<string> q;
        q.push(beginWord);

        int res=0;

        while(!q.empty())
        {
            res++;

            int len=q.size();
            for(int i=0;i<len;i++)
            {
                string word=q.front();
                q.pop();

                for(int j=0;j<word.length();j++)
                {
                    char ch=word[j];

                    for(char c='a';c<='z';c++)
                    {
                        word[j]=c;
                        if(st.find(word)==st.end())
                            continue;
                        if(word==endWord)
                            return res+1;
                        
                        st.erase(word);
                        q.push(word);

                    }
                    word[j]=ch;
                }
            }
        }
        return 0;
    }
};