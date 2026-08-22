class MyHashSet {
public:
    vector<list<int>> vec;
    MyHashSet() {
        vec.resize(10001,list<int>{});
    }
    
    void add(int key) {
        int index=key%10000;
        auto itr=find(vec[index].begin(),vec[index].end(),key);
        if(itr==vec[index].end()){
            vec[index].push_back(key);
        }
    }
    
    void remove(int key) {
        int index=key%10000;
        auto itr=find(vec[index].begin(),vec[index].end(),key);
        if(itr!=vec[index].end()){
            vec[index].erase(itr);
        }
    }
    
    bool contains(int key) {
        int index=key%10000;
        auto itr=find(vec[index].begin(),vec[index].end(),key);
        return itr!=vec[index].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
