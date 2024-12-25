class WordDictionary {
    vector<WordDictionary*> children;
    bool endOfWord;
public:
   WordDictionary(): endOfWord(false){
        children = vector<WordDictionary*>(26, nullptr);
    }
    
    void addWord(string word) {
        WordDictionary* node = this;
        for(char ch: word){
            if(node->children[ch-'a']==nullptr){
                node->children[ch-'a'] = new WordDictionary();
            }
            node = node->children[ch-'a'];
        }
        node->endOfWord = true;
        
    }
    
    bool search(string word) {
        WordDictionary* curr = this;
        for(int i=0;i<word.size();i++){
            char ch = word[i];
            if(ch=='.'){
                for(auto idx:curr->children){
                    if(idx && idx->search(word.substr(i+1))){
                        return true;
                    }
                }
                return false;
            }
            if(curr->children[ch-'a']==nullptr){
                return false;
            }
            curr = curr->children[ch-'a'];
        } 
        return curr && curr->endOfWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */