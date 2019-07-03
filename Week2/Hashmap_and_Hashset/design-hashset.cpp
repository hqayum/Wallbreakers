#define MAXSIZE 1000001

class MyHashSet {
public:
    
    bitset<MAXSIZE> boolArray;
    
    /** Initialize your data structure here. */
    MyHashSet() {
        
    }
    
    void add(int key) {
        boolArray[key] = 1;
    }
    
    void remove(int key) {
        boolArray[key] = 0;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return boolArray[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
 