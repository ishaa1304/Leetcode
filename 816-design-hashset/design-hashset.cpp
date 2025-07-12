class MyHashSet {
public:     
    bitset<1000001> map;
    MyHashSet() {}
    void add(int key) {
        map.set(key);
    }
    void remove(int key) {
        map.reset(key);
    }
    bool contains(int key) {
        return map[key];
    }
};