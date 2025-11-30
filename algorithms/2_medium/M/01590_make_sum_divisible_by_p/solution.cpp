class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = reduce(nums.begin(), nums.end(), 0LL);
        int rem{static_cast<int>(sum % static_cast<long long>(p))};

        if (rem == 0) {
            return 0;
        }

        int complement_rem{p - rem};
        unordered_map<int, int> hashmap;
        hashmap[0] = -1;

        int curr_rem{0};
        const size_t len{nums.size()};
        int min_eleme_to_remove{static_cast<int>(len)};

        for (size_t i{0}; i < len; ++i) {
            curr_rem = (curr_rem + nums[i]) % p;

            int target_rem{(curr_rem + complement_rem) % p};
            auto it{hashmap.find(target_rem)};

            if (it != hashmap.end()) {
                min_eleme_to_remove = min(min_eleme_to_remove, static_cast<int>(i) - it->second);
            }

            hashmap[curr_rem] = static_cast<int>(i);
        }

        return min_eleme_to_remove == static_cast<int>(len) ? -1 : static_cast<int>(min_eleme_to_remove);
    }
};
