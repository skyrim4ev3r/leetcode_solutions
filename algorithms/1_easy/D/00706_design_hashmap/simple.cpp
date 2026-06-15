constexpr int max_key = 1'000'000;
constexpr int min_key = 0;
constexpr int deleted_val = -1;

class MyHashMap {
    vector<int> table;
public:
    MyHashMap() {
        table.resize(max_key + 1, deleted_val);
    }

    void put(int key, int value) {
        assert(key <= max_key && key >= min_key);
        table[key] = value;
    }

    int get(int key) {
        assert(key <= max_key && key >= min_key);
        return table[key];
    }

    void remove(int key) {
        assert(key <= max_key && key >= min_key);
        table[key] = deleted_val;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
