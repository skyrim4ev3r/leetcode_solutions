constexpr size_t max_key = 1'000'000;
constexpr size_t min_key = 0;

class MyHashSet {
    vector<int> seen;
public:
    MyHashSet() {
        seen.resize(max_key + 1, false);
    }
    
    void add(int key) {
        assert(key <= max_key && key >= min_key);
        seen[key] = true;
    }
    
    void remove(int key) {
        assert(key <= max_key && key >= min_key);
        seen[key] = false;
    }
    
    bool contains(int key) {
        assert(key <= max_key && key >= min_key);
        return seen[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
