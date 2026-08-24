class Trie {
public:
    bool isLeaf;
    vector<Trie*> children;
    Trie() {
        isLeaf=false;
        children.resize(26,NULL);
    }
    
    void insert(string word) {
        Trie *curr=this;

        for(char ch:word)
        {
            int idx=ch-'a';

            if(curr->children[idx]==NULL)
                curr->children[idx]=new Trie();
            
            curr=curr->children[idx];
        }
        curr->isLeaf=true;
    }
    
    bool search(string word) {
        Trie *curr=this;

        for(char ch:word)
        {
            int idx=ch-'a';

            if(curr->children[idx]==NULL)
                return false;
            
            curr=curr->children[idx];
        }
        return curr->isLeaf;
    }
    
    bool startsWith(string prefix) {
        Trie * curr=this;

        for(char ch:prefix)
        {
            int idx=ch-'a';

            if(curr->children[idx]==NULL)
                return false;
            
            curr=curr->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */