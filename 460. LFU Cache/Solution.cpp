class LFUCache {
    unordered_map<int,list<pair<int,int>>> frequencies;
    unordered_map<int,pair<int,list<pair<int,int>>::iterator>> mp;
    int capacity;
    int minf;

    void insert(int key,int frequency, int value){
        frequencies[frequency].push_back({key,value});
        mp[key] = {frequency, --frequencies[frequency].end()};
    }
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minf=0;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        int f = mp[key].first;
        auto itr = mp[key].second;
        pair<int,int> kv = *itr;
        frequencies[f].erase(itr);
        if(frequencies[f].empty()){
            frequencies.erase(f);

            if(minf==f){
                ++minf;
            }
        }
        insert(kv.first,f+1,kv.second);
        return kv.second;
    }
    
    void put(int key, int value) {
        if(capacity<=0){
            return;
        }
        if(mp.find(key)!=mp.end()){
            mp[key].second->second = value;
            get(key);
            return ;
        }
        if(capacity == mp.size()){
            mp.erase(frequencies[minf].front().first);
            frequencies[minf].pop_front();

            if(frequencies[minf].empty()){
                frequencies.erase(minf);
            }
        }

        minf=1;
        insert(key, 1, value);

    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */