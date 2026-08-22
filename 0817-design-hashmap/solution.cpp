class MyHashMap {
public:
    vector<list<pair<int,int>>> buckets;
    int size=0;
    MyHashMap() {
        size=1e4;
        buckets.resize(size,list<pair<int,int>>{});
    }
    
    void put(int key, int value) {
        int ind=key%size;
        auto &chain=buckets[ind];
        for(auto it = chain.begin(); it != chain.end();it++){
            if(it->first==key){
                it->second=value;
                return;
            }
        }
        chain.emplace_back(key,value);
    }
    
    int get(int key) {
        int ind=key%size;
        auto &chain=buckets[ind];
        for(auto it = chain.begin(); it != chain.end();it++){
            if(it->first==key){
                return it->second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int ind=key%size;
        auto &chain=buckets[ind];
        for(auto it = chain.begin(); it != chain.end();it++){
            if(it->first==key){
                chain.erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
