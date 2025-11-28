class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int, int> hashmap{};
        const size_t x_len{x.size()};

        for (size_t i{0}; i < x_len; ++i) {
            hashmap[x[i]] = std::max(hashmap[x[i]], y[i]);
        }

        int max1{-1}, max2{-1}, max3{-1};

        for (const auto& [_, val] : hashmap) {
            if (val > max1) {
                max3 = max2;
                max2 = max1;
                max1 = val;
            } else if (val > max2) {
                max3 = max2;
                max2 = val;
            } else if (val > max3) {
                max3 = val;
            }
        }

        if (max3 == -1) {
            return -1;
        }

        return max1 + max2 + max3;
    }
};
