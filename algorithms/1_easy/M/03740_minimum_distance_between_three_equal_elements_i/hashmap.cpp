class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, tuple<int, int, int>> hashmap{};
        const size_t len{nums.size()};
        int min_diff{-1};

        for (size_t i{0}; i < len; ++i) {
            auto& data = hashmap[nums[i]];
            if (std::get<0>(data) == 0 && std::get<1>(data) == 0 && std::get<2>(data) == 0) {
                data = std::make_tuple(-1, -1, -1);
            }

            if (get<0>(data) == -1) {
                get<0>(data) = static_cast<int>(i);
            } else if (get<1>(data) == -1) {
                get<1>(data) = static_cast<int>(i);
            } else {
                if (get<2>(data) == -1) {
                    get<2>(data) = static_cast<int>(i);
                } else {
                    get<0>(data) = get<1>(data);
                    get<1>(data) = get<2>(data);
                    get<2>(data) = static_cast<int>(i);
                }

                const int curr_diff{(get<2>(data) - get<0>(data)) * 2};

                if (min_diff == -1 || curr_diff < min_diff) {
                    min_diff = curr_diff;
                }
            }
        }

        return min_diff;
    }
};
