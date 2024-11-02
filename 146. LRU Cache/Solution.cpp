class LRUCache {
    class Cache {
      public:
        int key;
        int value;
        Cache* prev;
        Cache* next;

        Cache(int key,int value){
            this->key=key;
            this->value=value;
            prev=NULL;
            next=NULL;
        }
    };
    Cache* head=new Cache(-1,-1);
    Cache* tail=new Cache(-1,-1);
    int size;
    int capacity;
    unordered_map<int,Cache*> mp;

    void deleteNode(Cache* node){
        Cache* prevNode = node->prev;
        Cache* afterNode = node->next;
        prevNode->next = afterNode;
        afterNode->prev = prevNode;
    }

    void insertAfterHead(Cache* node){
        Cache* currAfterHead= head->next;
        head->next = node;
        node->next = currAfterHead;
        node->prev = head;
        currAfterHead->prev = node;
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        size=0;
        mp.clear();
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        Cache* node = mp[key];
        // node->prev->next = node->next;
        // node->next= head->next;
        // node->prev = head;
        // head->next = node;
        deleteNode(node);
        insertAfterHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Cache* node = mp[key];
            node->value = value;
            deleteNode(node);
            insertAfterHead(node);
        } else {
            if(mp.size()==capacity){
                Cache* node = tail->prev;
                mp.erase(node->key);
                deleteNode(node);
            }
            Cache* node = new Cache(key,value);
            mp[key]=node;
            insertAfterHead(node);
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */