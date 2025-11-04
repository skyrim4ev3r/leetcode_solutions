class SmallestInfiniteSet {
    set<int> candidates_in_removed_range;
    int inf_set_min;
public:
    SmallestInfiniteSet(): inf_set_min{1} {
    }

    int popSmallest() {
        if (candidates_in_removed_range.empty()) {
            int smallest_num{inf_set_min};
            inf_set_min += 1;
            return smallest_num;
        } else {
            int smallest_num{*candidates_in_removed_range.begin()};
            candidates_in_removed_range.erase(candidates_in_removed_range.begin());
            return smallest_num;
        }
    }

    void addBack(int num) {
        if (num < inf_set_min) {
            candidates_in_removed_range.insert(num);

            while (candidates_in_removed_range.erase(inf_set_min - 1)) {
                inf_set_min -= 1;
            }
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
