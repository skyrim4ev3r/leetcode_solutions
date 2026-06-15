struct Entity {
    int val;
    bool is_deleted;
    bool is_fill;
};

class MyHashSet {
    Entity* ptr;
    size_t cap;
    size_t load;
    size_t resize_at;
    size_t fill_cnt;
public:
    MyHashSet(const MyHashSet&) = delete;
    MyHashSet& operator=(const MyHashSet&) = delete;

    MyHashSet() {
        ptr = nullptr;
        cap = 0;
        load = 0;
        resize_at = 0;
        fill_cnt = 0;
    }

    MyHashSet(const size_t cap) {
        ptr = static_cast<Entity*>(malloc(cap * sizeof(*ptr)));
        assert(ptr != nullptr);
        for (size_t i = 0; i < cap; i += 1) {
            ptr[i].is_fill = false;
            ptr[i].is_deleted = false;
        }
        this->cap = cap;
        resize_at = (3 * cap) / 4;
        load = 0;
        fill_cnt = 0;
    }

    ~MyHashSet() {
        cap = 0;
        load = 0;
        free(ptr);
        ptr = nullptr;
    }

    void add(int key) noexcept {
        if (fill_cnt == resize_at) {
            const size_t new_cap = std::max(4uz, (cap >= load * 2) ? cap : 2 * cap);
            auto temp_set = MyHashSet(new_cap);
            for (size_t i = 0; i < cap; i += 1) {
                if (ptr[i].is_fill && !ptr[i].is_deleted) {
                    temp_set.add(ptr[i].val);
                }
            }
            Entity* swap_ptr = temp_set.ptr;
            temp_set.ptr = this->ptr;
            this->ptr = swap_ptr;

            cap = temp_set.cap;
            load = temp_set.load;
            resize_at = temp_set.resize_at;
            fill_cnt = temp_set.fill_cnt;
        }   

        const size_t init_pos = static_cast<size_t>(key) % cap;
        size_t idx = init_pos;
        size_t empty_spot = cap;
        while (ptr[idx].is_fill) {
            if (!ptr[idx].is_deleted && ptr[idx].val == key) { 
                return;
            }

            if (empty_spot == cap && ptr[idx].is_deleted) {
                empty_spot = idx;
            }

            idx = idx + 1 == cap ? 0 : idx + 1;

            if (idx == init_pos) {
                break;
            }
        }

        load += 1;

        if (empty_spot != cap) {
            ptr[empty_spot].is_fill = true;
            ptr[empty_spot].is_deleted = false;
            ptr[empty_spot].val = key;
        } else {
            ptr[idx].is_fill = true;
            ptr[idx].is_deleted = false;
            ptr[idx].val = key;
            fill_cnt += 1;
        }
    }

    void remove(int key) {
        if (load == 0) { return; }

        const size_t intit_pos = static_cast<size_t>(key) % cap;
        size_t idx = intit_pos;

        while (ptr[idx].is_fill) {
            if (!ptr[idx].is_deleted && ptr[idx].val == key) {
                ptr[idx].is_deleted = true;
                load -= 1;
                return;
            }

            idx = idx + 1 == cap ? 0 : idx + 1;

            if (idx == intit_pos) {
                return;
            }
        }
    }

    bool contains(int key) {
        if (load == 0) { return false; }

        const size_t intit_pos = static_cast<size_t>(key) % cap;
        size_t idx = intit_pos;

        while (ptr[idx].is_fill) {
            if (!ptr[idx].is_deleted && ptr[idx].val == key) {
                return true;
            }

            idx = idx + 1 == cap ? 0 : idx + 1;

            if (idx == intit_pos) {
                return false;
            }
        }

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
