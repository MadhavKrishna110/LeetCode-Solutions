class MapSum {
    vector<MapSum*> children;
    int prefixSum;
    bool isEndOfWord;
public:
    MapSum() {
        children = vector<MapSum*>(26,nullptr);
        prefixSum=0;
        isEndOfWord=false;
    }
    
    void insert(string key, int val) {
        MapSum* curr = this;
        for(char ch:key){
            if(curr->children[ch-'a']==nullptr){
                curr->children[ch-'a']= new MapSum();
            }
            curr = curr->children[ch-'a'];
        }
        curr->prefixSum=val;
        curr->isEndOfWord=true;
    }

    int sumRecursive(MapSum* node){
            int totalSum=node->prefixSum;
        for(int i=0;i<26;i++){
            if(node->children[i]!=nullptr){
                totalSum+=sumRecursive(node->children[i]);
            }
        }
        return totalSum;
    }
    
    int sum(string prefix) {
        MapSum* curr = this;
        for(char ch:prefix){
            if(curr->children[ch-'a']==nullptr){
                return 0;
            }
            curr= curr->children[ch-'a'];
        }
        
        
        return sumRecursive(curr);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */