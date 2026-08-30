class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;

        while(ss>>word)
            words.push_back(word);
        
        reverse(words.begin(),words.end());

        string result;
        for(auto w:words)
        {
            result+=w;
            result+=' ';
        }
        result.pop_back();
        return result;
    }
};