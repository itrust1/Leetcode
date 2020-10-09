class LRUCache {
private:
    int max_capacity;
    unordered_map<int,int> mp;
    unordered_map<int,int> count_in_queue;
    queue<int> accessed;
public:
    LRUCache(int capacity) {
        max_capacity = capacity;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            accessed.push(key);
            count_in_queue[key]++;
            return mp[key];
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        if(mp.size()==max_capacity && mp.find(key)==mp.end()){
            while(count_in_queue[accessed.front()] !=1){
                count_in_queue[accessed.front()]--;
                accessed.pop();
            }
            mp.erase(mp.find(accessed.front()) );
            count_in_queue[accessed.front()]--;
            accessed.pop();
        }
        mp[key] = value;
        accessed.push(key);
        count_in_queue[key]++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/*
optimal approach - very useful - learnt about list implementation in C++ STL
*/
 
 class LRUCache {
private:
    int max_capacity;
    unordered_map<int,int> mp1;
    unordered_map<int,list<int>::iterator> mp2;
    list<int> l;
    // MRU - Most Recently Used  
    // LRU - Least Recently Used
    
    // DATA STRUCTURES NEEDED
    // mp1 => key to value
    // mp2 => key to their iterator in LRUlist 
    //    we need mp2 so that if we access the same key again we have to delete it from LRUlist by using its iterator and then add it in the front of LRUlist as it is MRU
    // LRUlist => List containing keys in order such that MRU .... LRU
    
public:
    
    LRUCache(int capacity) {
        max_capacity = capacity;
    }
    
    int get(int key) {
        if(mp1.find(key)==mp1.end())
            return -1;
        updateLRU(key);// removes the earlier accession from l and add this key to the front of l
        return mp1[key];
    }
    
    void put(int key, int value) {
        if(mp1.size()==max_capacity && mp1.find(key)==mp1.end()){
            evict(); // removes the last key in l from mp1, mp2 and l also
        }
        updateLRU(key);
        mp1[key] = value;// here key can be new or old, so updateLRU must check for that
    }
    void updateLRU(int key){
        if(mp2.find(key)==mp2.end()){
            l.push_front(key);
            mp2[key] = l.begin();
            return;
        }
        l.erase(mp2[key]);
        l.push_front(key);
        mp2[key] = l.begin();
    }
    void evict(){
        mp2.erase(l.back());
        mp1.erase(l.back());
        l.pop_back();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 
